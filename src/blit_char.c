/*
** blit_char.c for my_tar.h in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 11:53:59 2009 valentin horner
** Last update Thu Apr 22 19:14:04 2010 Valentin Horner
*/

#include <stdio.h>
#include "colors.h"
#include "t_screen.h"
#include "xprint.h"

void	blit_char(t_screen *screen, int x, int y, int mode, char c)
{
  if (x >= screen->cur_x || x < 0 || y >= screen->cur_y || y < 0)
    return ;
  x *= 2;
  screen->image[y][x] = (char)mode;
  screen->image[y][x + 1] = c;
}
