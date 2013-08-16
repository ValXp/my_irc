/*
** gere_keys.h for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 19:11:17 2009 valentin horner
** Last update Sat Apr 24 10:36:56 2010 Valentin Horner
*/

#ifndef GERE_KEYS_H_
# define GERE_KEYS_H_

# define        KEY_RIGHT	"\033[C"
# define        KEY_LEFT	"\033[D"
# define        KEY_UP		"\033[A"
# define        KEY_DOWN	"\033[B"
# define        KEY_ESC         "\033"
# define        KEY_CTRLA       "\001"
# define        KEY_CTRLE       "\005"
# define	KEY_CTRLK	"\013"
# define	KEY_CTRLY	"\031"
# define	KEY_BACK	"\b"
# define	KEY_BACKSPACE	"\177"
# define	KEY_CL		"\14"
# define	KEY_TAB		"\t"

void	gere_keys(t_app *app, t_screen *screen, char *buffer);

#endif /* !GERE_KEYS_H_ */
