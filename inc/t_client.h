/*
** t_client.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 11:01:49 2010 Valentin Horner
** Last update Thu Apr 22 18:34:03 2010 Valentin Horner
*/

#ifndef T_CLIENT_H_
# define T_CLIENT_H_

typedef struct		s_client
{
  int			fd;
  char			*command;
  char			*data;
  char			*nick;
  int			can_execute;
  time_t		last_activity;
  int			id;
  struct s_channel	*chan;
  struct timeval	ping;
  struct s_client	*next;
}			t_client;

/*
** Fontions de gestion de la liste chainee
*/

t_client	*add_client(t_client *mother, int fd);
t_client	*remove_client(t_client *mother, t_client *to_remove);
void		free_client(t_client *to_free);
t_client	*client_by_nick(t_client *mother, char *nick);

#endif /* T_CLIENT_H_ */
