/*
** xprint.c for my_ftp in /home/horner_v/proj/tek2/c/my_ftp/d_serveur
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Dec 23 19:20:24 2009 valentin horner
** Last update Thu Apr 22 19:24:21 2010 Valentin Horner
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __powerpc__
# define _XOPEN_SOURCE 600
# define _ISOC99_SOURCE
#endif
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "xprint.h"

int		xprintf(char *format, ...)
{
  va_list	args;
  int		len;

  va_start(args, *format);
  if ((len = vprintf(format, args)) < 0)
    exit(EXIT_FAILURE);
  va_end(args);
  return (len);
}

int		xfprintf(FILE *file, char *format, ...)
{
  va_list	args;
  int		len;

  va_start(args, *format);
  if ((len = vfprintf(file, format, args)) < 0)
    exit(EXIT_FAILURE);
  va_end(args);
  return (len);
}

int		xsprintf(char *str, char *format, ...)
{
  va_list	args;
  int		len;

  va_start(args, *format);
  if ((len = vsprintf(str, format, args)) < 0)
    exit(EXIT_FAILURE);
  va_end(args);
  return (len);
}

int		xwrite(int fd, void *ptr, int size)
{
  int		len;

  if ((len = write(fd, ptr, size)) < 0)
    exit(EXIT_FAILURE);
  return (len);
}

int		xsscanf(char *string, char *format, ...)
{
  va_list	args;
  int		len;

  va_start(args, *format);
  if ((len = vsscanf(string, format, args)) < 0)
    exit(EXIT_FAILURE);
  va_end(args);
  return (len);
}

void	xputerror(const char *format)
{
  fprintf(stderr, format);
  exit(EXIT_SUCCESS);
}

