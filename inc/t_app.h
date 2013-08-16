/*
** t_app.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sat Apr 24 09:07:45 2010 Valentin Horner
** Last update Sat Apr 24 09:31:51 2010 Valentin Horner
*/

#ifndef T_APP_H_
# define T_APP_H_

typedef struct		s_app
{
  struct s_screen	*screen;
  int			fd;
}			t_app;

#endif /* T_APP_H_ */
