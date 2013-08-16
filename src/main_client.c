/*
** main_serveur.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 10:41:19 2010 Valentin Horner
** Last update Thu Apr 29 23:08:48 2010 valentin horner
*/

#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "t_app.h"
#include "init_app.h"
#include "t_screen.h"
#include "init_screen.h"
#include "init_input.h"
#include "resize.h"
#include "draw_screen.h"
#include "get_screen.h"
#include "gere_keys.h"
#include "stop_screen.h"
#include "xmemory.h"
#include "select_it.h"

int		main(void)
{
  t_app		*app;

  app = init_app();
  select_it(app);
  stop_app(app);
  return (0);
}
