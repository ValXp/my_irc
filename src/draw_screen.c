/*
** draw_screen.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 14:36:10 2009 valentin horner
** Last update Thu Apr 29 20:45:54 2010 valentin horner
*/

#include <stdio.h>
#include "colors.h"
#include "t_screen.h"
#include "filp_screen.h"
#include "put_bg.h"
#include "put_window.h"
#include "put_screen.h"
#include "draw_text.h"

void		update_buffer(t_screen *screen)
{
  put_screen(screen);
  draw_text(screen, 3, 3, screen->cur_x - 26,
	    screen->cur_y - 10, screen->chat_text);
  draw_text(screen, screen->cur_x - 19, 3, 
	    16, screen->cur_y - 10, screen->users_text);
  draw_text(screen, 3, screen->cur_y - 4,
	    screen->cur_x - 6, 1, screen->type_text);
  filp_screen(screen);
}

void		draw_screen(t_screen *screen)
{
  static int	retry;
  static int	pending;

  if (pending)
    {
      retry = 1;
      screen->stop_screen = 1;
      printf(C_BG_BLUE "\033[H\033[2J");
      return ;
    }
  if (!retry && !pending)
    pending = 1;
  update_buffer(screen);
  if (retry)
    {
      screen->stop_screen = 0;
      retry = 0;
      pending = 0;
      draw_screen(screen);
    }
  pending = 0;
}
