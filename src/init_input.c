/*
** init_input.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 10:34:13 2009 valentin horner
** Last update Fri Apr 23 14:58:43 2010 Valentin Horner
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
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/termios.h>
#include "colors.h"
#include "t_screen.h"
#include "init_input.h"
#include "xprint.h"


void			init_input(int mode)
{
  struct termios	att;

#ifdef __linux__
  if (tcgetattr(0, &att) < 0)
#else
  if (ioctl(0, TIOCGETA, &att) < 0)
#endif
    {
      xfprintf(stderr, "Error Getting ioctl\n");
      exit(EXIT_FAILURE);
    }
  if (mode == QUIT)
    {
      xprintf("\033[?25h" RESET_MODE);
      att.c_lflag |= ECHO;
      att.c_lflag |= ICANON;
    }
  if (mode == RUN)
    {
      xprintf("\033[?25l");
      att.c_lflag &= ~ECHO;
      att.c_lflag &= ~ICANON;
      att.c_cc[VMIN] = 1;
      att.c_cc[VTIME] = 0;
    }
#ifdef __linux__
  if (tcsetattr(0, TCSANOW, &att) < 0)
#else
  if (ioctl(0, TIOCSETA, &att) < 0)
#endif
    {
      xfprintf(stderr, "Error Setting ioctl\n");
      exit(EXIT_FAILURE);
    }
}

