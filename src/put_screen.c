/*
** put_screen.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 16:58:26 2009 valentin horner
** Last update Sat Apr 24 09:23:36 2010 Valentin Horner
*/

#include <stdio.h>
#include "t_screen.h"
#include "xprint.h"
#include "put_bg.h"
#include "put_screen.h"
#include "put_window.h"

void		put_screen(t_screen *screen)
{
  char		buffer[512];

  sprintf(buffer, "IRC : Updated : %d", screen->up);
  put_bg(screen, buffer);
  put_window(screen, 2, 2, 
	     screen->cur_x - 24, screen->cur_y - 9, "Chat");
  put_window(screen, screen->cur_x - 20, 2, 
	     18, screen->cur_y - 9, "Users");
  put_window(screen, 2, screen->cur_y - 5,
	     screen->cur_x - 4, 3, "Your message");
}
