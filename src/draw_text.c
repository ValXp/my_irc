/*
** draw_text.c for my_irc in /usr/home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Fri Apr 23 16:23:42 2010 Valentin Horner
** Last update Thu Apr 29 23:15:43 2010 valentin horner
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "t_screen.h"
#include "xmemory.h"
#include "blit_string.h"
#include "colors.h"

int	ret_lines(char *str, int w)
{
  int	count;
  int	ch;

  count = 0;
  ch = 0;
  --str;
  while (*(++str))
    {
      if (*str == '\n')
	{
	  count++;
	  ch = 0;
	}
      else
	if (++ch >= w)
	  {
	    count++;      
	    ch = 0;
	  }
    }
  return (count);
}

char	*resize_text(char *text, int w, int h)
{
  while (strlen(text) > 4096)
    strcpy(text, text + 512);
  while (*text && ret_lines(text, w) >= h)
    ++text;
  return (text);
}

void	draw_text(t_screen *screen, int x, int y, int w, int h, char *text)
{
  char	*buffer;
  int	cur;
  int	type;

  if (!text || w < 4 || h < 1)
    return ;
  type = 0;
  if (!strcmp(screen->type_text, text))
    type = 1;
  buffer = xmalloc(w + 4);
  text = resize_text(text, w, h);
  while (*text)
    {
      cur = -1;
      --text;
      while (++cur < w && *(++text) && *text != '\n')
	buffer[cur] = *text;
      if (*text == '\n')
	text++;
      buffer[cur] = 0;
      blit_string(screen, x, y++, F_TITLE_FG_MODE, buffer);
      if (type)
	blit_string(screen, x + (strlen(buffer)), y - 1, F_FOLDER_FG_MODE, "|");
    }
  free(buffer);
}
