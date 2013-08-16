/*
** launch_server.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 12:18:59 2010 Valentin Horner
** Last update Wed Apr 21 17:29:50 2010 Valentin Horner
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"
#include "t_command.h"

static void	create_socket(t_serveur *serveur, int port)
{
  printf(INFO "Creating socket at port %d ..." END, port);
  serveur->fd = socket(PF_INET, SOCK_STREAM, 0);
  if (serveur->fd < 1)
    xputerror(ERROR_SOCKET_CREATE);
  serveur->sin.sin_addr.s_addr = htonl(INADDR_ANY);
  serveur->sin.sin_family = AF_INET;
  serveur->sin.sin_port = htons(port);
}

static void	listen_to_me(t_serveur *serveur)
{
  printf(INFO "Binding socket ..." END);
  if (bind(serveur->fd, (struct sockaddr*)&serveur->sin,
	   sizeof(serveur->sin)))
    xputerror(FATAL "Cannot bind socket !" END);
  if (listen(serveur->fd, 42))
    xputerror(ERROR_LISTENING_SOCKET);
}

t_serveur	*launch_serveur(int port)
{
  t_serveur	*serveur;

  serveur = xmalloc(sizeof(*serveur));
  serveur->com = init_commands();
  serveur->channels = add_channel(serveur->channels, "global");
  create_socket(serveur, port);
  listen_to_me(serveur);
  return (serveur);
}

