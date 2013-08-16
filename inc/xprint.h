/*
** xprint.h for my_ftp in /home/horner_v/proj/tek2/c/my_ftp/d_serveur
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Dec 23 19:35:44 2009 valentin horner
** Last update Thu Apr 22 19:24:47 2010 Valentin Horner
*/

#ifndef XPRINT_H_
# define XPRINT_H_
#if defined __sun__ || defined __i486__ || __linux__
int	vsscanf(char *str, char *format, ...);
#endif /* __sun__ || __i486__ */

int	xprintf(char *format, ...);
int	xfprintf(FILE *file, char *format, ...);
int	xsprintf(char *str, char *format, ...);
int	xwrite(int fd, void *ptr, int size);
int	xsscanf(char *string, char *format, ...);
void	xputerror(const char *error);

#endif /* !XPRINT_H_ */
