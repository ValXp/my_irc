/*
** filp_screen.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 12:13:57 2009 valentin horner
** Last update Thu Apr 29 20:32:22 2010 valentin horner
*/

#include <stdio.h>
#include "colors.h"
#include "t_screen.h"
#include "init_screen.h"
#include "xprint.h"
#include "show_line.h"

void	filp_screen(t_screen *screen)
{
  int	cur;
  char	**swap;

  cur = -1;
  if (screen->moved)
    init_screen(screen);
  xprintf(GOTO_BEGIN);
  screen->up = 0;
  while (++cur < screen->cur_y && !screen->stop_screen)
    {
      screen->up += show_line(screen, cur);
      if (cur + 1 < screen->cur_y)
	xprintf(RESET_MODE "\n");
    }
  xprintf(RESET_MODE);
  fflush(stdout);
  swap = screen->image;
  screen->image = screen->old_image;
  screen->old_image = swap;
}
