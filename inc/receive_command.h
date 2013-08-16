/*
** receive_command.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 14:30:03 2010 Valentin Horner
** Last update Thu Apr 22 14:20:53 2010 Valentin Horner
*/

#ifndef RECEIVE_COMMAND_H_
# define RECEIVE_COMMAND_H_
# define BUFF_SIZE	12

void	serveur_command(t_serveur *serveur);
int	client_command(t_serveur *serveur, t_client *client);

#endif /* RECEIVE_COMMAND_H_ */
