/*
** join.c for my_ftp in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 14:58:32 2010 Valentin Horner
** Last update Wed Apr 28 11:18:17 2010 Valentin Horner
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
#include "leave.h"
#include "send_new_listing.h"

int		join(t_serveur *serveur, t_client *client, char **resp)
{
  t_channel	*found;

  if (!resp || !resp[0] || !resp[1] || resp[1][0] != '#')
    {
      append_data(client, "* command failed");
      return (0);
    }
  send_all(client, "* ");
  send_all(client, client->nick);
  send_all(client, " leave channel");
  leave(serveur, client, 0);
  if (!(found = channel_from_name(serveur->channels, resp[1] + 1)))
    {
      serveur->channels = add_channel(serveur->channels, resp[1] + 1);
      if (!(found = channel_from_name(serveur->channels, resp[1] + 1)))
	return (0);
    }
  found->users = add_user(found->users, client);
  client->chan = found;
  send_all(client, "* ");
  send_all(client, client->nick);
  send_all(client, " has join channel");
  append_data(client, "* You join #");
  append_data(client, client->chan->name);
  send_new_listing(serveur);
  return (0);
}
