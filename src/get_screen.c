/*
** get_screen.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 10:43:27 2009 valentin horner
** Last update Sat Apr 24 09:15:31 2010 Valentin Horner
*/

#include <stdlib.h>
#include "t_screen.h"
#include "xmemory.h"

t_screen		*get_screen(t_screen *screen)
{
  static t_screen	*save;
  
  if (screen)
    save = screen;
  return (save);
}
