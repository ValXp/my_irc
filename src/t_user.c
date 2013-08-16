/*
** t_user.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 11:08:28 2010 Valentin Horner
** Last update Tue Apr 27 10:15:14 2010 Valentin Horner
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"

t_user	*add_user(t_user *mother, t_client *client)
{
  t_user	*new;

  new = xmalloc(sizeof(*new));
  new->client = client;
  new->next = mother;
  return (new);
}

t_user	*remove_user(t_user *mother, t_user *to_remove)
{
  t_user	*last;
  t_user	*new_mother;

  if (mother == NULL)
    return (0);
  if (to_remove == NULL)
    return (mother);
  if (mother == to_remove)
    {
      new_mother = to_remove->next;
      free_user(to_remove);
      return (new_mother);
    }
  last = mother;
  while (last->next && last->next != to_remove)
    last = last->next;
  if (!last->next)
    return (mother);
  to_remove = last->next;
  last->next = last->next->next;
  free_user(to_remove);
  return (mother);
}

void	free_user(t_user *to_free)
{
  if (to_free == NULL)
    return ;
  free(to_free);
}

t_user	*user_by_client(t_user *mother, t_client *me)
{
  while (mother && mother->client != me)
    mother = mother->next;
  return (mother);
}
