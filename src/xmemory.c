/*
** xmemory.c for my_ftp in /home/horner_v/proj/tek2/c/my_ftp/d_serveur
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Dec 23 19:18:20 2009 valentin horner
** Last update Thu Apr 22 19:26:04 2010 Valentin Horner
*/

#ifdef __linux__
# define _BSD_SOURCE
#endif
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "xprint.h"
#include "errors.h"

void	*xmalloc(size_t size)
{
  void	*pointer;

  pointer = malloc(size);
  if (pointer == NULL)
    xputerror(MALLOC_ERROR);
  bzero(pointer, size);
  return (pointer);
}

void	*xrealloc(void *old, size_t size)
{
  void	*pointer;

  pointer = realloc(old, size);
  if (pointer == NULL)
    xputerror(MALLOC_ERROR);
  return (pointer);
}

char	*xstrdup(char *src)
{
  char	*ret;

  ret = strdup(src);
  if (ret == NULL)
    xputerror(MALLOC_ERROR);
  return (ret);
}

int	xstrlen(char *str)
{
  if (str == NULL)
    return (0);
  return (strlen(str));
}
