/*
** xmemory.h for my_ftp in /home/horner_v/proj/tek2/c/my_ftp/d_serveur
** 
** Made by valentin horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Dec 23 19:35:12 2009 valentin horner
** Last update Wed Apr 21 14:15:48 2010 Valentin Horner
*/

#ifndef XMEMORY_H_
# define XMEMORY_H_

void	*xmalloc(size_t size);
void	*xrealloc(void *old, size_t size);
char	*xstrdup(char *src);
int	xstrlen(char *str);

#endif /* !XMEMORY_H_ */
