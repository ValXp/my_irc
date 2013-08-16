/*
** msg.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 17:09:53 2010 Valentin Horner
** Last update Thu Apr 22 18:41:56 2010 Valentin Horner
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

int		msg(t_serveur *serveur, t_client *client, char **resp)
{
  t_client	*dest;

  if (!resp || !resp[0] || !resp[1] || !resp[2])
    {
      append_data(client, "* command failed\n");
      return (0);
    }
  if (!(dest = client_by_nick(serveur->clients, resp[1])))
    {
      append_data(client, "* no such user\n");
      return (0);
    }
  append_data(dest, "[");
  append_data(dest, client->nick);
  append_data(dest, "] ");
  append_data(dest, resp[2]);
  return (0);
}
