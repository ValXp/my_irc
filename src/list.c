/*
** list.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 16:02:18 2010 Valentin Horner
** Last update Thu Apr 22 17:31:42 2010 Valentin Horner
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

int		list(t_serveur *serveur, t_client *client, char **resp)
{
  t_channel	*cur;

  cur = serveur->channels;
  append_data(client, "* listing channels ...");
  if (resp && resp[0] && resp[1])
    {
      append_data(client, "\n* how name contains : ");
      append_data(client, resp[1]);
    }
  while (cur)
    {
      if ((resp && resp[0] && resp[1] && strstr(cur->name, resp[1])) ||
	  (!resp || !resp[0] || !resp[1]))
	{
	  append_data(client, "\n-> #");
	  append_data(client, cur->name);
	}
      cur = cur->next;
    }
  append_data(client, "\n* listing done !");
  return (0);
}
