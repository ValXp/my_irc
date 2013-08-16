/*
** run_loop.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 12:40:45 2010 Valentin Horner
** Last update Wed Apr 28 11:26:59 2010 Valentin Horner
*/

#ifdef __linux__
# define _BSD_SOURCE
#endif

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"
#include "receive_command.h"
#include "build_set.h"
#include "interpret_command.h"
#include "run_loop.h"

void			connect_client(t_serveur *serveur)
{
  int			fd;
  struct sockaddr_in	sin;
  int			sin_size;
  t_channel		*global;

  fd = accept(serveur->fd, (struct sockaddr*)&sin, (socklen_t*)&sin_size);
  if (fd < 0)
    {
      printf(ERROR_SOCKET_ACCEPT);
      return ;
    }
  serveur->clients = add_client(serveur->clients, fd);
  serveur->clients->id = serveur->client_nb++;
  global = channel_from_name(serveur->channels, "global");
  global->users = add_user(global->users, serveur->clients);
  serveur->clients->chan = global;
  printf(INFO "A new client is HERE !! <%d>" END, serveur->clients->id);
}

void	loop_clients(t_serveur *serveur, fd_set *read_set, fd_set *write_set)
{
  int		sent;
  t_client	*cur;

  sent = 0;
  cur = serveur->clients;
  while (cur)
    {
      if (FD_ISSET(cur->fd, read_set) && ++sent && 
	  client_command(serveur, cur))
	cur = serveur->clients;
      if (cur && FD_ISSET(cur->fd, write_set))
	sent += send_data(cur);
      if (cur)
	cur = cur->next;
    }
  if (!sent)
    usleep(100);
}

void		run_loop(t_serveur *serveur)
{
  fd_set	read_set;
  fd_set	write_set;
  int		bigger;

  while (1)
    {
      bigger = build_set(serveur, &read_set);
      build_set(serveur, &write_set);
      if (select(bigger + 1, &read_set, &write_set, 0, 0) < 0)
	continue;
      if (FD_ISSET(0, &read_set))
	serveur_command(serveur);
      if (FD_ISSET(serveur->fd, &read_set))
	connect_client(serveur);
      loop_clients(serveur, &read_set, &write_set);
    }
}
