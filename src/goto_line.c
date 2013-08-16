/*
** goto_line.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 16:50:52 2009 valentin horner
** Last update Sun May 24 17:05:41 2009 valentin horner
*/

#include <stdio.h>
#include <stdlib.h>
#include "xprint.h"

void	goto_line(int pos)
{
  xprintf("\033[%d;0f", pos + 1);
}
