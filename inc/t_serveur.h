/*
** t_serveur.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 12:02:41 2010 Valentin Horner
** Last update Wed Apr 21 17:15:11 2010 Valentin Horner
*/

#ifndef T_SERVEUR_H_
# define T_SERVEUR_H_

typedef struct		s_serveur
{
  int			fd;
  t_client		*clients;
  t_channel		*channels;
  struct sockaddr_in	sin;
  int			client_nb;
  struct s_command	*com;
}			t_serveur;

#endif /* T_SERVEUR_H_ */
