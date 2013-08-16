/*
** show_line.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 16:46:41 2009 valentin horner
** Last update Fri Apr 23 21:58:09 2010 Valentin Horner
*/

#include <stdio.h>
#include <string.h>
#include "t_screen.h"
#include "colors.h"
#include "xprint.h"

static void	put_mode(char mode)
{
  if (mode == F_BG_MODE)
    xprintf(BG_MODE);
  if (mode == F_TITLE_BG_MODE)
    xprintf(TITLE_BG_MODE);
  if (mode == F_FG_MODE)
    xprintf(FG_MODE);
  if (mode == F_TITLE_FG_MODE)
    xprintf(TITLE_FG_MODE);
  if (mode == F_FG_LIGHT_MODE)
    xprintf(FG_LIGHT_MODE);
  if (mode == F_SHADOW_MODE)
    xprintf(SHADOW_MODE);
  if (mode == F_FOLDER_FG_MODE)
    xprintf(FOLDER_FG_MODE);
  if (mode == F_FILE_FG_MODE)
    xprintf(FILE_FG_MODE);
  return ;
}

int		show_line(t_screen *screen, int line)
{
  int		cur;

  if (line >= screen->cur_y || line < 0)
    return (0);
  if (!strcmp(screen->image[line], screen->old_image[line]))
    return (0);
  cur = 0;
  while (cur < screen->cur_x * 2)
    {
      put_mode(screen->image[line][cur++]);
      xprintf("%c", screen->image[line][cur++]);
    }
  xprintf(TEXT_MODE);
  return (1);
}
