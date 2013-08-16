/*
** to_wordtab.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 17:03:58 2010 Valentin Horner
** Last update Tue Apr 27 10:21:59 2010 Valentin Horner
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "xmemory.h"

char	*mstrsep(char **str, char sep)
{
  char	*found;
  char	*last;

  last = *str;
  if ((found = strchr(*str, sep)))
    {
      *str = found + 2;
      *found = 0;
      *(found + 1) = 0;
      return (last);
    }
  if (**str == 0)
    return (0);
  *str = *str + strlen(*str);
  return (last);
}

char	**to_wordtab(char *total_get)
{
  char	*token;
  char	**out;
  int	nb;

  nb = 0;
  out = 0;
  while ((token = mstrsep(&total_get, 31)) != NULL)
    {
      out = xrealloc(out, (++nb) * sizeof(*out));
      out[nb - 1] = token;
    }
  out = xrealloc(out, (++nb) * sizeof(*out));
  out[nb - 1] = 0;
  return (out);
}
