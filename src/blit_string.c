/*
** blit_string.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 11:58:07 2009 valentin horner
** Last update Thu Apr 22 19:14:28 2010 Valentin Horner
*/

#include "colors.h"
#include "t_screen.h"
#include "blit_char.h"

void	blit_string(t_screen *screen, int x, int y, int mode, char *s)
{
  int	cur;

  cur = -1;
  while (s[++cur])
    blit_char(screen, x + cur, y, mode, s[cur]);
}

