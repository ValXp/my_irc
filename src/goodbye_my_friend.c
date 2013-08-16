/*
** goodbye_my_friend.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 28 11:30:15 2010 Valentin Horner
** Last update Thu Apr 29 21:31:27 2010 valentin horner
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"
#include "t_command.h"

void		goodbye_my_friend(t_serveur *serveur)
{
  printf(INFO "Closing Clients ..." END);
  while (serveur->clients)
    serveur->clients = remove_client(serveur->clients, serveur->clients);
  printf(INFO "Closing Channels ..." END);
  while (serveur->channels)
    {
      while (serveur->channels->users)
	serveur->channels->users = remove_user(serveur->channels->users,
					       serveur->channels->users);
      serveur->channels = remove_channel(serveur->channels, serveur->channels);
    }
  printf(INFO "Closing commands ..." END);
  free_command(serveur->com);
  shutdown(serveur->fd, SHUT_RDWR);
  close(serveur->fd);
  free(serveur);
}
