/*
** init_app.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sat Apr 24 09:06:11 2010 Valentin Horner
** Last update Thu Apr 29 21:38:16 2010 valentin horner
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "t_app.h"
#include "t_screen.h"
#include "init_screen.h"
#include "init_input.h"
#include "resize.h"
#include "draw_screen.h"
#include "get_screen.h"
#include "gere_keys.h"
#include "xmemory.h"
#include "stop_screen.h"
#include "append_message.h"

t_app	*init_app(void)
{
  t_app	*app;

  app = xmalloc(sizeof(*app));
  app->screen = xmalloc(sizeof(*(app->screen)));
  app->screen->chat_text = xstrdup("** Welcome to the IRC client !\n");
  append_message(&(app->screen->chat_text), "** You are not connected\n");
  append_message(&(app->screen->chat_text), "** Use /connect host [port]\n");
  app->screen->type_text = xstrdup("/connect ");
  app->screen->users_text = xstrdup("Nobody ...");
  get_screen(app->screen);
  init_screen(app->screen);
  init_input(RUN);
  draw_screen(app->screen);
  signal(SIGWINCH, resize);
  return (app);
}

void	stop_app(t_app *app)
{
  stop_screen(app->screen);
  if (app->fd)
  {
    shutdown(app->fd, SHUT_RDWR);
    close(app->fd);
  }
  free(app->screen->type_text);
  free(app->screen->chat_text);
  free(app->screen->users_text);
  free(app->screen);
  free(app);
  init_input(QUIT);
  printf("\033[H\033[2JGoodBye !\n");
  fflush(stdout);
  exit(EXIT_SUCCESS);
}
