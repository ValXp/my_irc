/*
** t_channel.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 11:08:28 2010 Valentin Horner
** Last update Thu Apr 22 12:30:11 2010 Valentin Horner
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"

t_channel	*add_channel(t_channel *mother, char *name)
{
  t_channel	*new;

  new = xmalloc(sizeof(*new));
  new->name = xstrdup(name);
  new->next = mother;
  return (new);
}

t_channel	*remove_channel(t_channel *mother, t_channel *to_remove)
{
  t_channel	*last;
  t_channel	*new_mother;

  if (mother == NULL)
    return (0);
  if (to_remove == NULL)
    return (mother);
  if (mother == to_remove)
    {
      new_mother = to_remove->next;
      free_channel(to_remove);
      return (new_mother);
    }
  last = mother;
  while (last->next && last->next != to_remove)
    last = last->next;
  if (!last->next)
    return (mother);
  to_remove = last->next;
  last->next = last->next->next;
  free_channel(to_remove);
  return (mother);
}

void	free_channel(t_channel *to_free)
{
  if (to_free == NULL)
    return ;
  free(to_free->name);
  free(to_free);
}

t_channel	*channel_from_name(t_channel *mother, char *name)
{
  while (mother && strcmp(mother->name, name))
    mother = mother->next;
  return (mother);
}
