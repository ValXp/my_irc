/*
** gere_keys.c for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 19:10:18 2009 valentin horner
** Last update Wed Apr 28 16:49:17 2010 Valentin Horner
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "t_app.h"
#include "t_screen.h"
#include "gere_keys.h"
#include "colors.h"
#include "xmemory.h"
#include "append_message.h"
#include "parse_command.h"

int	is_good(char *str)
{
  --str;
  while (*(++str) && (isprint(*str) || *str == '\n'));
  if (!*str)
    return (1);
  return (0);
 }

void	gere_keys(t_app *app, t_screen *screen, char *buffer)
{
  if (!strncmp(buffer, KEY_BACKSPACE, strlen(KEY_BACKSPACE)))
    {
      if (strlen(screen->type_text))
	screen->type_text[strlen(screen->type_text) - 1] = 0;
      return ;
    }
  if (strncmp(buffer, ESC, strlen(ESC)) && is_good(buffer))
    {
      screen->type_text = xrealloc(screen->type_text,
				   strlen(screen->type_text) + 
				   strlen(buffer) + 2);
      strcat(screen->type_text, buffer);
    }
  if (strchr(screen->type_text, '\n'))
    {
      parse_command(app, screen->type_text);
      *screen->type_text = 0;
    }
}
