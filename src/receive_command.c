/*
** receive_command.c for my_ftp in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 14:08:43 2010 Valentin Horner
** Last update Thu Apr 29 21:23:27 2010 valentin horner
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
#include "receive_command.h"
#include "interpret_command.h"
#include "quit.h"
#include "goodbye_my_friend.h"

int	client_command(t_serveur *serveur, t_client *client)
{
  char	buffer[BUFF_SIZE];
  char	*found;

  bzero(buffer, BUFF_SIZE);
  if (recv(client->fd, buffer, BUFF_SIZE - 1, 0) <= 0)
    {
      printf(WARN "%d Client disconnected" END, client->id);
      quit(serveur, client, 0);
      return (1);
    }
  if (!client->command)
    client->command = xmalloc(BUFF_SIZE);
  client->command = xrealloc(client->command, 
			     xstrlen(client->command) + BUFF_SIZE);
  strncat(client->command, buffer, BUFF_SIZE);
  if ((found = strchr(client->command, '\n')))
    {
      *found = 0;
      if (interpret_client(serveur, client))
	return (1);
      *client->command = 0;
      free(client->command);
      client->command = 0;
    }
  return (0);
}

void		serveur_command(t_serveur *serveur)
{
  static char	*command;
  char		buffer[BUFF_SIZE];
  char		*found;

  UNUSED(serveur)
  bzero(buffer, BUFF_SIZE);
  if (read(0, buffer, BUFF_SIZE - 1) < 0)
    printf(WARN "Bad read from stdin !!" END);
  if (!command)
    command = xmalloc(BUFF_SIZE);
  command = xrealloc(command, xstrlen(command) + BUFF_SIZE);
  strncat(command, buffer, BUFF_SIZE - 1);
  if ((found = strchr(command, '\n')))
    {
      *found = 0;
      goodbye_my_friend(serveur);
      free(command);
      exit(EXIT_SUCCESS);
    }
}
