/*
** quit.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Thu Apr 22 10:39:59 2010 Valentin Horner
** Last update Wed Apr 28 11:12:39 2010 Valentin Horner
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

int	quit(t_serveur *serveur, t_client *client, char **resp)
{
  printf(INFO "%s quit server" END, client->nick);
  send_all(client, "* ");
  send_all(client, client->nick);
  send_all(client, " has quit");
  if (resp && resp[0] && resp[1])
    {
      send_all(client, " (");
      send_all(client, resp[1]);
      send_all(client, ")");
    }
  leave(serveur, client, 0);
  serveur->clients = remove_client(serveur->clients, client);
  send_new_listing(serveur);
  return (1);
}

