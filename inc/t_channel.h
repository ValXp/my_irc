/*
** t_channel.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 11:01:49 2010 Valentin Horner
** Last update Wed Apr 21 16:26:57 2010 Valentin Horner
*/

#ifndef T_CHANNEL_H_
# define T_CHANNEL_H_

typedef struct		s_channel
{
  char			*name;
  t_user		*users;
  struct s_channel	*next;
}			t_channel;

/*
** Fontions de gestion de la liste chainee
*/

t_channel	*add_channel(t_channel *mother, char *name);
t_channel	*remove_channel(t_channel *mother, t_channel *to_remove);
void		free_channel(t_channel *to_free);
t_channel	*channel_from_name(t_channel *mother, char *name);

#endif /* T_CHANNEL_H_ */
