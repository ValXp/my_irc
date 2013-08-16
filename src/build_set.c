/*
** build_set.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 12:46:01 2010 Valentin Horner
** Last update Wed Apr 21 15:28:56 2010 Valentin Horner
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/select.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"

int		build_set(t_serveur *serveur, fd_set *set)
{
  int		bigger;
  t_client	*cur;

  FD_ZERO(set);
  FD_SET(serveur->fd, set);
  FD_SET(0, set);
  bigger = serveur->fd;
  cur = serveur->clients;
  while (cur)
    {
      FD_SET(cur->fd, set);
      if (cur->fd > bigger)
	bigger = cur->fd;
      cur = cur->next;
    }
  return (bigger);
}

