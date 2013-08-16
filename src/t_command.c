/*
** t_command.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 16:45:31 2010 Valentin Horner
** Last update Thu Apr 22 18:44:12 2010 Valentin Horner
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdlib.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"
#include "t_command.h"
#include "nick.h"
#include "quit.h"
#include "leave.h"
#include "users.h"
#include "join.h"
#include "list.h"
#include "msg.h"

t_command	*init_commands(void)
{
  t_command	*com;

  com = 0;
  com = add_command(com, "/nick", nick);
  com = add_command(com, "/quit", quit);
  com = add_command(com, "/part", leave);
  com = add_command(com, "/leave", leave);
  com = add_command(com, "/users", users);
  com = add_command(com, "/join", join);
  com = add_command(com, "/list", list);
  com = add_command(com, "/msg", msg);
  return (com);
}

t_command	*add_command(t_command *father, char *name, command_t func)
{
  t_command	*new;

  new = xmalloc(sizeof(*new));
  new->name = xstrdup(name);
  new->func = func;
  new->next = father;
  return (new);
}

void		free_command(t_command *com)
{
  t_command	*to_free;

  while (com)
    {
      free(com->name);
      to_free = com;
      com = com->next;
      free(to_free);
    }
}
