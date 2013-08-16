/*
** build_client_set.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sat Apr 24 12:47:09 2010 Valentin Horner
** Last update Sat Apr 24 12:57:13 2010 Valentin Horner
*/

#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include "t_app.h"

int	build_client_set(t_app *app, fd_set *set)
{
  int	bigger;

  bigger = 0;
  FD_ZERO(set);
  FD_SET(0, set);
  if (app->fd)
    FD_SET(app->fd, set);
  bigger = app->fd;
  return (bigger);
}
