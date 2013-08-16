/*
** interpret_command.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 16:58:12 2010 Valentin Horner
** Last update Thu Apr 29 21:24:39 2010 valentin horner
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
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
#include "to_wordtab.h"

void	append_data(t_client *client, char *data)
{
  if (!client->data)
    client->data = xmalloc(strlen(data) + 4);
  else
    client->data = xrealloc(client->data, 
			    strlen(client->data) + strlen(data) + 4);
  strcat(client->data, data);
}

int		send_data(t_client *client)
{
  int		sent;

  sent = 0;
  if (!client->data)
    return (0);
  strcat(client->data, "\n");
  sent = send(client->fd, client->data, strlen(client->data), 0);
  free(client->data);
  client->data = 0;
  return (sent);
}

void		send_all(t_client *client, char *str)
{
  t_user	*cur;

  cur = client->chan->users;
  while (cur)
    {
      if (cur->client != client)
	append_data(cur->client, str);
      cur = cur->next;
    }
}

void	usay(t_client *client)
{
  send_all(client, "<");
  append_data(client, "<you> ");
  append_data(client, client->command);
  send_all(client, client->nick);
  send_all(client, "> ");
  send_all(client, client->command);
}

int		interpret_client(t_serveur *serveur, t_client *client)
{
  char		**response;
  t_command	*com;
  int		ret;

  ret = 0;
  response = to_wordtab(client->command);
  if (!response || !response[0])
    {
      free(response);
      return (0);
    }
  com = serveur->com;
  while (com && strncasecmp(com->name, response[0], strlen(com->name)))
    com = com->next;
  if (com)
    ret = com->func(serveur, client, response);
  else
    usay(client);
  free(response);
  return (ret);
}
