/*
** connect_to_server.c for my_ftp in /home/horner_v/tek2/c/my_ftp
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun Apr 11 20:49:18 2010 Valentin Horner
** Last update Sat Apr 24 12:27:42 2010 Valentin Horner
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "errors.h"
#include "xprint.h"
#include "append_message.h"
#include "t_screen.h"
#include "draw_screen.h"
#include "t_app.h"

static int	resolve(t_app *app, struct sockaddr_in *sin,
			char **s, char *host)
{
  struct hostent	*h;
  in_addr_t		addr;

  if ((addr = inet_addr(host)) == INADDR_NONE)
    {
      append_message(s, "** Resolution de l'hote ...\n");
      draw_screen(app->screen);
      if ((h = gethostbyname(host)) == NULL)
	{
	  append_message(s, "** Cette adresse n'existe pas !\n");
	  return (1);
	}
      else
	sin->sin_addr = *((struct in_addr*)h->h_addr_list[0]);
    }
  else
    sin->sin_addr.s_addr = addr;
  return (0);
}

int			connect_to_server(t_app *app, char **s, 
					  char *host, int port)
{
  struct sockaddr_in	sin;
  int			sock;

  if (resolve(app, &sin, s, host))
    return (0);
  if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    xputerror(ERROR_SOCKET_CREATE);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  append_message(s, "** Connection au serveur ...\n");
  draw_screen(app->screen);
  if (connect(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)))
    {
      append_message(s, "** Echec de la connection.\n");
      return (0);
    }
  append_message(s, "** Connection reussie !\n");
  return (sock);
}
