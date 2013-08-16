/*
** check_before_append.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Tue Apr 27 17:07:15 2010 Valentin Horner
** Last update Wed Apr 28 11:54:26 2010 Valentin Horner
*/

#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include "errors.h"
#include "t_app.h"
#include "t_screen.h"
#include "append_message.h"
#include "check_before_append.h"

void	new_list(t_app *app, int *listing, char *found)
{
  char		*found1;

  *found = 0;
  *app->screen->users_text = 0;
  if ((found1 = strchr(found + 1, 31)))
    {
      *found1 = 0;
      append_message(&(app->screen->users_text), found + 1);
      strcpy(found, found1 + 1);
    }
  else
    {
      *listing = 1;
      append_message(&(app->screen->users_text), found + 1);
    }
}

int		check_before_append(t_app *app, char *buffer)
{
  static int	listing;
  char		*found;

  if (!listing && (found = strchr(buffer, 31)))
    {
      new_list(app, &listing, found);
      return (1);
    }
  if (listing && (found = strchr(buffer, 31)))
    {
      *found = 0;
      append_message(&(app->screen->users_text), buffer);
      strcpy(buffer, found + 1);
      listing = 0;
      return (1);
    }
  if (listing)
    append_message(&(app->screen->users_text), buffer);
  return (0);
}
