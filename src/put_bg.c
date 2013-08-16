/*
** put_bg.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 11:29:45 2009 valentin horner
** Last update Fri Apr 23 11:26:25 2010 Valentin Horner
*/

#include "colors.h"
#include "t_screen.h"
#include "blit_char.h"
#include "blit_string.h"

void	put_bg(t_screen *screen, char *title)
{
  int	cur;
  int	cur1;

  cur = -1;
  while (++cur < screen->cur_y)
    {
      cur1 = -1;
      while (++cur1 < screen->cur_x)
	blit_char(screen, cur1, cur, F_BG_MODE, ' ');
    }
  blit_string(screen, 1, 0, F_TITLE_BG_MODE, title);
  cur = 0;
  while (++cur < screen->cur_x)
    blit_char(screen, cur, 1, F_TITLE_BG_MODE, '-');
}
