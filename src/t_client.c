/*
** t_client.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 11:08:28 2010 Valentin Horner
** Last update Thu Apr 22 18:38:10 2010 Valentin Horner
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"

t_client	*add_client(t_client *mother, int fd)
{
  t_client	*new;

  new = xmalloc(sizeof(*new));
  new->fd = fd;
  new->nick = xstrdup("NO_NAME");
  new->last_activity = time(0);
  new->next = mother;
  return (new);
}

t_client	*remove_client(t_client *mother, t_client *to_remove)
{
  t_client	*last;
  t_client	*new_mother;

  if (mother == NULL)
    return (0);
  if (to_remove == NULL)
    return (mother);
  if (mother == to_remove)
    {
      new_mother = to_remove->next;
      free_client(to_remove);
      return (new_mother);
    }
  last = mother;
  while (last->next && last->next != to_remove)
    last = last->next;
  if (!last->next)
    return (mother);
  to_remove = last->next;
  last->next = last->next->next;
  free_client(to_remove);
  return (mother);
}

void	free_client(t_client *to_free)
{
  if (to_free == NULL)
    return ;
  shutdown(to_free->fd, SHUT_RDWR);
  close(to_free->fd);
  free(to_free->command);
  free(to_free->nick);
  free(to_free);
}

t_client	*client_by_nick(t_client *mother, char *nick)
{
  while (mother && strcmp(mother->nick, nick))
    mother = mother->next;
  return (mother);
}
