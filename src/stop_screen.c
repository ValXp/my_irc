/*
** stop_screen.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 11:22:21 2009 valentin horner
** Last update Fri Apr 23 18:18:24 2010 Valentin Horner
*/

#include <stdlib.h>
#include <strings.h>
#include "t_screen.h"

static void	free_image(char **image, int height)
{
  int		cur;

  cur = -1;
  while (++cur < height)
    free(image[cur]);
  free(image);
}

void	stop_screen(t_screen *screen)
{
  free_image(screen->image, screen->cur_y);
  free_image(screen->old_image, screen->cur_y);
  screen->moved = 0;
}
