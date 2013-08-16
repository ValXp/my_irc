/*
** nick.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 09:53:44 2010 Valentin Horner
** Last update Wed Apr 28 12:33:21 2010 Valentin Horner
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"
#include "t_command.h"
#include "interpret_command.h"
#include "send_new_listing.h"

int	find_nick(t_client *cur, char *nick)
{
  if (!strcmp(nick, "you"))
    return (1);
  while (cur)
    {
      if (!strcmp(cur->nick, nick))
	return (1);
      cur = cur->next;
    }
  return (0);
}

char	*check_nick(t_serveur *serveur, t_client *client, char *onick)
{
  char	*nick;

  nick = xstrdup(onick);
  while (find_nick(serveur->clients, nick))
    {
      nick = xrealloc(nick, xstrlen(nick) + 2);
      strcat(nick, "_");
    }
  if (strcmp(nick, onick))
    {
      append_data(client, "* this nick is already used, using ");
      append_data(client, nick);
    }
  else
    {
      append_data(client, "* Your nickname has changed : ");
      append_data(client, nick);
    }
  return (nick);
}

int	nick(t_serveur *serveur, t_client *client, char **resp)
{
  char	*new_nick;

  if (!resp || !resp[0] || !resp[1])
    {
      append_data(client, "* command failed");
      return (0);
    }
  new_nick = check_nick(serveur, client, resp[1]);
  if (strcmp(client->nick, "NO_NAME"))
    {
      send_all(client, "* ");
      send_all(client, client->nick);
      send_all(client, " is know as ");
      send_all(client, new_nick);
    }
  else
    {
      send_all(client, "* ");
      send_all(client, new_nick);
      send_all(client, " has join ");
      send_all(client, client->chan->name);
    }
  free(client->nick);
  client->nick = new_nick;
  send_new_listing(serveur);
  return (0);
}
