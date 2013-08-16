/*
** interpret_command.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 17:10:16 2010 Valentin Horner
** Last update Tue Apr 27 10:29:18 2010 Valentin Horner
*/

#ifndef INTERPRET_COMMAND_H_
# define INTERPRET_COMMAND_H_

int	interpret_client(t_serveur *serveur, t_client *client);
int	send_data(t_client *client);
void	send_all(t_client *client, char *str);
void	append_data(t_client *client, char *data);

#endif /* INTERPRET_COMMAND_H_ */
