/*
** put_window.h for my_tar in /home/horner_v/proj/c/my_tar/leaf
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Sun May 24 10:14:51 2009 valentin horner
** Last update Wed Apr 28 14:38:47 2010 Valentin Horner
*/

#ifndef PUT_WINDOW_H_
# define PUT_WINDOW_H_
# define X	0
# define Y	1
# define O_X	2
# define O_Y	3
# define W	4
# define H	5

void	put_window(t_screen *screen, int x, int y,
		   int width, int height, char *title);

#endif /* !PUT_WINDOW_H_ */
