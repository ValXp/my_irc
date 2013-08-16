/*
** parse_command.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sat Apr 24 10:07:07 2010 Valentin Horner
** Last update Thu Apr 29 21:34:03 2010 valentin horner
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include "t_app.h"
#include "t_screen.h"
#include "xmemory.h"
#include "append_message.h"
#include "connect_to_server.h"
#include "init_app.h"

char	*replace_spaces(char *cp)
{
  int	count;
  char	*found;
  int	pos;

  count = 0;
  found = cp;
  while ((found = strchr(found, ' ')) && count < 2)
    {
      pos = found - cp;
      cp = xrealloc(cp, strlen(cp) + 3);
      memmove(cp + pos + 1, cp + pos, strlen(cp + pos) + 1);
      cp[pos] = 31;
      found = cp + pos + 2;
      count++;
    }
  return (cp);
}

void	send_nick(int fd)
{
  char	*tutu;
  char	*name;

  if (!fd)
    return ;
  if (!(name = xstrdup(getenv("USER"))))
    name = xstrdup("NO_NAME");
  tutu = xmalloc(strlen(name) + 10);
  sprintf(tutu, "/nick %s\n", name);
  tutu = replace_spaces(tutu);
  send(fd, tutu, strlen(tutu), 0);
  free(name);
  free(tutu);
}

void	try_connect(t_app *app, char *com)
{
  int	port;
  char	*host;
  char	*found;

  port = 4242;
  host = 0;
  found = com;
  while (*found && (found = strchr(found, ' ')))
    {
      if (!host)
	host = ++found;
      else
	port = atoi(++found);
    }
  if ((found = strchr(host, ' ')) || (found = strchr(host, '\n')))
    *found = 0;
  app->fd = connect_to_server(app, &(app->screen->chat_text), host, port);
  send_nick(app->fd);
}

void	parse_command(t_app *app, char *com)
{
  char *cp;

  if (!strncmp(com, "/quit", strlen("/quit")))
    stop_app(app);
  if (!app->fd)
    {
      if (strncmp(com, "/connect ", strlen("/connect ")))
	append_message(&(app->screen->chat_text),
		       "** vous n'etes pas connecte\n");
      else
	try_connect(app, com);
      return ;
    }
  cp = xstrdup(com);
  if (*cp == '/')
    cp = replace_spaces(cp);
  send(app->fd, cp, strlen(cp), 0);
  free(cp);
}
