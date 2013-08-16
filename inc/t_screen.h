/*
** t_screen.h for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 10:08:10 2009 valentin horner
** Last update Thu Apr 29 20:40:52 2010 valentin horner
*/

#ifndef T_SCREEN_H_
# define T_SCREEN_H_

typedef struct	s_screen
{
  int		cur_x;
  int		cur_y;
  int		rea_x;
  int		rea_y;
  char		**image;
  char		**old_image;
  int		moved;
  int		up;
  char		*chat_text;
  char		*users_text;
  char		*type_text;
  int		stop_screen;
}		t_screen;

#endif /* !T_SCREEN_H_ */
