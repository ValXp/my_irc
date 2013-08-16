/*
** t_command.h for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 16:41:13 2010 Valentin Horner
** Last update Wed Apr 21 17:25:56 2010 Valentin Horner
*/

#ifndef T_COMMAND_H_
# define T_COMMAND_H_

typedef int	(*command_t)(t_serveur*, t_client*, char **);

typedef struct		s_command
{
  struct s_command	*next;
  char			*name;
  command_t		func;
}			t_command;

/*
** Fonctions de manipulation de la liste
*/
t_command	*init_commands(void);
t_command	*add_command(t_command *father, char *name, command_t func);
void		free_command(t_command *com);

#endif /* T_COMMAND_H_ */
