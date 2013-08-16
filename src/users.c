/*
** users.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 11:44:45 2010 Valentin Horner
** Last update Tue Apr 27 10:19:18 2010 Valentin Horner
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

void		list_all_users(t_serveur *serveur, t_client *client)
{
  t_client	*cur;

  cur = serveur->clients;
  append_data(client, "* listing users connected to server");
  while (cur)
    {
      append_data(client, "\n-> ");
      append_data(client, cur->nick);
      cur = cur->next;
    }
  append_data(client, "\n* listing complete !");
}

int		users(t_serveur *serveur, t_client *client, char **resp)
{
  t_user	*cur;

  if (resp && resp[0] && resp[1] && !strcmp(resp[1], "all"))
    {
      list_all_users(serveur, client);
      return (0);
    }
  cur = client->chan->users;
  append_data(client, "* listing users on #");
  append_data(client, client->chan->name);
  while (cur)
    {
      append_data(client, "\n-> ");
      append_data(client, cur->client->nick);
      cur = cur->next;
    }
  append_data(client, "\n* listing complete !");
  serveur = serveur;
  resp = resp;
  return (0);
}
