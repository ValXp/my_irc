/*
** send_new_listing.c for my_irc in /usr/home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Tue Apr 27 17:20:32 2010 Valentin Horner
** Last update Wed Apr 28 11:16:11 2010 Valentin Horner
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

void		send_new_listing(t_serveur *serveur)
{
  t_client	*cur;
  t_user	*ucur;
  char		toto[2];

  cur = serveur->clients;
  toto[0] = 31;
  toto[1] = 0;
  while (cur)
    {
      ucur = cur->chan->users;
      append_data(cur, toto);
      while (ucur)
	{
	  if (cur != ucur->client)
	    append_data(cur, ucur->client->nick);
	  else
	    append_data(cur, "you");
	  append_data(cur, "\n");
	  ucur = ucur->next;
	}
      append_data(cur, toto);
      cur = cur->next;
    }
}
