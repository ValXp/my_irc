/*
** select_it.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sat Apr 24 12:31:10 2010 Valentin Horner
** Last update Thu Apr 29 21:32:36 2010 valentin horner
*/

#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "t_app.h"
#include "t_screen.h"
#include "draw_screen.h"
#include "get_screen.h"
#include "gere_keys.h"
#include "xmemory.h"
#include "errors.h"
#include "xprint.h"
#include "append_message.h"
#include "build_client_set.h"
#include "check_before_append.h"
#include "init_app.h"

void		read_it(t_app *app, fd_set *read_set, char *buffer)
{
  bzero(buffer, 512);
  if (app->fd && FD_ISSET(app->fd, read_set))
    {
      if (recv(app->fd, buffer, 510, 0) > 0)
	{
	  while (check_before_append(app, buffer));
	  append_message(&(app->screen->chat_text), buffer);
	}
      else
	stop_app(app);
    }
  bzero(buffer, 512);
  if (FD_ISSET(0, read_set) && read(0, buffer, 4) <= 0)
    bzero(buffer, 512);

}

void		select_it(t_app * app)
{
  char		buffer[512];
  fd_set	read_set;
  int		bigger;
  int		ignore;

  ignore = 0;
  bzero(buffer, 512);
  while (strcmp(buffer, "\033"))
    {
      if (*buffer && !ignore)
	gere_keys(app, app->screen, buffer);
      else
	ignore = 0;
      draw_screen(app->screen);
      bigger = build_client_set(app, &read_set);
      if (select(bigger + 1, &read_set, 0, 0, 0) < 0)
	{
	  ignore = 1;
	  continue;
	}
      read_it(app, &read_set, buffer);
    }
}
