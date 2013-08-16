/*
** t_user.h for my_ftp in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 11:41:27 2010 Valentin Horner
** Last update Thu Apr 22 11:02:21 2010 Valentin Horner
*/

#ifndef T_USER_H_
# define T_USER_H_


typedef struct		s_user
{
  t_client		*client;
  struct s_user		*next;
}			t_user;

/*
** Fontions de gestion de la liste chainee
*/

t_user		*add_user(t_user *mother, t_client *client);
t_user		*remove_user(t_user *mother, t_user *to_remove);
void		free_user(t_user *to_free);
t_user		*user_by_client(t_user *mother, t_client *me);

#endif /* T_USER_H_ */
