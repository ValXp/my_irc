/*
** leave.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 10:43:18 2010 Valentin Horner
** Last update Wed Apr 28 14:42:57 2010 Valentin Horner
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

void		to_global(t_serveur *serveur, t_client *client)
{
  t_channel	*global;

  send_all(client, "* ");
  send_all(client, client->nick);
  send_all(client, " leave channel");
  global = channel_from_name(serveur->channels, "global");
  global->users = add_user(global->users, client);
  client->chan = global;
  append_data(client, "* You join #global");
  send_all(client, "* ");
  send_all(client, client->nick);
  send_all(client, " has join global");  
}

int		leave(t_serveur *serveur, t_client *client, char **resp)
{
  t_channel	*last;
  t_channel	*global;

  last = client->chan;
  global = channel_from_name(serveur->channels, "global");
  if (resp && client->chan == global)
    {
      append_data(client, "* you cannot leave this channel");
      return (0);
    }
  if (!resp || client->chan != global)
    client->chan->users = 
      remove_user(client->chan->users, 
		  user_by_client(client->chan->users, client));
  if (resp && client->chan != global)
    to_global(serveur, client);
  if (!last->users && last != global)
    serveur->channels = remove_channel(serveur->channels, last);
  if (resp)
    send_new_listing(serveur);
  return (0);
}
