/*
** append_message.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sat Apr 24 09:35:39 2010 Valentin Horner
** Last update Sat Apr 24 09:40:21 2010 Valentin Horner
*/

#include <string.h>
#include <stdlib.h>
#include "xmemory.h"

void	append_message(char **dest, char *msg)
{
  if (!msg)
    return ;
  *dest = xrealloc(*dest, strlen(*dest) + strlen(msg) + 2);
  strcat(*dest, msg);
}
