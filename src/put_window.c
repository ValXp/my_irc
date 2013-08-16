/*
** put_window.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 12:34:27 2009 valentin horner
** Last update Fri Apr 23 16:16:17 2010 Valentin Horner
*/

#include <string.h>
#include "colors.h"
#include "t_screen.h"
#include "blit_char.h"
#include "blit_string.h"
#include "put_window.h"

static void	fill_window(t_screen *screen, int vals[6])
{
  blit_char(screen, vals[X], vals[Y], F_FG_MODE, ' ');
  if (vals[Y] == vals[O_Y])
    blit_char(screen, vals[X], vals[Y], F_FG_LIGHT_MODE, 'q');
  if (vals[Y] == vals[H] + vals[O_Y] - 1)
    blit_char(screen, vals[X], vals[Y], F_FG_MODE, 'q');
  if (vals[X] == vals[O_X] + vals[W] - 1)
    blit_char(screen, vals[X], vals[Y], F_FG_MODE, 'x');
  if (vals[X] == vals[O_X])
    blit_char(screen, vals[X], vals[Y], F_FG_LIGHT_MODE, 'x');
  if (vals[Y] == vals[O_Y] && vals[X] == vals[O_X])
    blit_char(screen, vals[X], vals[Y], F_FG_LIGHT_MODE, 'l');
  if (vals[Y] == vals[O_Y] && vals[X] == vals[O_X] + vals[W] - 1)
    blit_char(screen, vals[X], vals[Y], F_FG_LIGHT_MODE, 'k');
  if (vals[Y] == vals[O_Y] + vals[H]  - 1 && vals[X] == vals[O_X] + vals[W] - 1)
    blit_char(screen, vals[X], vals[Y], F_FG_MODE, 'j');
  if (vals[Y] == vals[O_Y] + vals[H]  - 1 && vals[X] == vals[O_X])
    blit_char(screen, vals[X], vals[Y], F_FG_MODE, 'm');
}

static void	put_bg_box(t_screen *screen, int x, int y, 
			   int width, int height)
{
  int	cur;
  int	cur1;
  int	vals[6];

  cur = y - 1;
  while (++cur < (y + height) + 1)
    {
      cur1 = x - 1;
      while (++cur1 < x + width && cur < y + height)
	{
	  vals[0] = cur1;
	  vals[1] = cur;
	  vals[2] = x;
	  vals[3] = y;
	  vals[4] = width;
	  vals[5] = height;
	  fill_window(screen, vals);
	}
      while (++cur1 < x + width + 1 && cur >= y + height)
	blit_char(screen, cur1, cur, F_SHADOW_MODE, ' ');
      if (cur > y)
	blit_char(screen, --cur1, cur, F_SHADOW_MODE, ' ');
    }
}

void	put_window(t_screen *screen, int x, int y,
		   int width, int height, char *title)
{
  put_bg_box(screen, x, y, width, height);
  blit_char(screen, x + (width / 2) - (strlen(title) / 2) - 2,
	    y, F_FG_LIGHT_MODE, 'u');
  blit_char(screen, x + (width / 2) + (strlen(title) / 2) - 
	    !(strlen(title) % 2), y, F_FG_LIGHT_MODE, 't');
  blit_string(screen, x + (width / 2) - (strlen(title) / 2) 
	      - 1, y, F_TITLE_FG_MODE, title);
}
