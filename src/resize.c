/*
** resize.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 10:39:53 2009 valentin horner
** Last update Thu Apr 29 20:06:34 2010 valentin horner
*/

#ifdef __sun__
# include <stropts.h>
# include <sys/types.h>

# define TIOCGETA TCGETA
# define TIOCSETA TCSETA
# define termios termio

# include <fcntl.h>
#else
# include <sys/fcntl.h>
#endif /* __sun__ */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/termios.h>
#include "t_screen.h"
#include "get_screen.h"
#include "xprint.h"
#include "draw_screen.h"

void			resize(int sig)
{
  t_screen		*screen;
  struct winsize	w;

  screen = get_screen(0);
  if (ioctl(0, TIOCGWINSZ, &w) < 0)
    {
      xfprintf(stderr, "Can't get win size !\n");
      exit(EXIT_FAILURE);
    }
  screen->rea_x = w.ws_col;
  screen->rea_y = w.ws_row;
  screen->moved = 0;
  if (sig == SIGWINCH)
    {
      signal(SIGWINCH, resize);
      screen->moved = 1;
      draw_screen(screen);
    }
}
