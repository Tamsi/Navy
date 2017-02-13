/*
** game.c for  in /home/tbesson/projet_psu/PSU_2016_navy
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Feb  9 10:51:16 2017 Tamsi Besson
** Last update Thu Feb  9 10:51:17 2017 Tamsi Besson
*/

#include "my.h"

void play(int pid)
{
  char *s;
  my_putstr("attack:\t");
  s = get_next_line(0);
  if (s != NULL)
  {
    if (check_coo(s) == 0)
    {
      my_putstr("wrong position\n");
      play(pid);
    }
    else
      send_msg(pid, ATTACK, coo_to_nb(s));
  }
}

void game()
{
  int i;

  i = 0;
  my_putstr("my pid: ");
  my_put_nbr(getpid());
  my_putstr("\n");
  if (SERV_CLIENT == 1)
    my_putstr("waiting for enemy connexion...\n");
  while (1)
  {
    if (i > 16 && ATK_CHECKER != 0)
    {
      i = 0;
      my_putstr("waiting for enemy's attack...\n");
    }
    pause ();
    i++;
  }
}

void handler(int signum)
{
  struct sigaction action;
  action.sa_sigaction = receiver;
  action.sa_flags = SA_SIGINFO;
  if (sigaction(signum, &action, NULL))
    exit (-1);
}

int disp_usage()
{
  write(1, "USAGE\n", 6);
  write(1, "\t./navy [first_player_pid] navy_positions\n", 42);
  write(1, "\nDESCRIPTION\n", 13);
  write(1, "\tfirst_player_pid\tonly for the 2nd player.", 43);
  write(1, " pid of the first player.\n", 26);
  write(1, "\tnavy_positions\t\t", 17);
  write(1, "file representing the positions of the ships.\n", 46);
  return (0);
}
