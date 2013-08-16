/*
** main_serveur.c for my_irc in /home/horner_v/tek2/c/my_irc
** 
** Made by Valentin Horner
** Login   <horner_v@epitech.net>
** 
** Started on  Wed Apr 21 10:41:19 2010 Valentin Horner
** Last update Wed Apr 21 17:26:10 2010 Valentin Horner
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include "errors.h"
#include "xmemory.h"
#include "xprint.h"
#include "t_client.h"
#include "t_user.h"
#include "t_channel.h"
#include "t_serveur.h"
#include "t_command.h"
#include "launch_server.h"
#include "run_loop.h"

int		main(int ac, char **av)
{
  t_serveur	*serveur;

  if (ac < 2)
    xputerror(FATAL "Need a port to listen in parameter" END);
  printf(INFO "This is the server !" END);
  printf(INFO "Launching server ..." END);
  serveur = launch_serveur(atoi(av[1]));
  printf(INFO "Running Loop ..." END);
  run_loop(serveur);
  return (0);
}
