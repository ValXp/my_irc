/*
** init_screen.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 10:17:25 2009 valentin horner
** Last update Fri Apr 23 21:52:11 2010 Valentin Horner
*/

#include <strings.h>
#include <stdlib.h>
#include <signal.h>
#include "xmemory.h"
#include "t_screen.h"
#include "init_screen.h"
#include "resize.h"
#include "stop_screen.h"
#include "draw_screen.h"

static void	create_image(t_screen *screen)
{
  int		cur;

  screen->cur_x = screen->rea_x;
  screen->cur_y = screen->rea_y;
  screen->moved = 0;
  screen->image = xmalloc(sizeof(char*) * (screen->cur_y));
  screen->old_image = xmalloc(sizeof(char*) * (screen->cur_y));
  cur = -1;
  while (++cur < screen->cur_y)
    {
      screen->image[cur] = xmalloc(sizeof(char) * (screen->cur_x + 1) * 2);
      screen->old_image[cur] = xmalloc(sizeof(char) * (screen->cur_x + 1) * 2);
    }
}

void	init_screen(t_screen *screen)
{
  if (screen->moved)
    stop_screen(screen);
  resize(0);
  create_image(screen);
  draw_screen(screen);
}
