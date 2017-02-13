/*
** message.c for  in /home/tbesson/projet_psu/PSU_2016_navy
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Feb  9 10:53:48 2017 Tamsi Besson
** Last update Thu Feb  9 11:44:37 2017 Tamsi Besson
*/

#include "my.h"

void decoder(int nb_msg, int nb_data, int pid)
{
  if (nb_msg == 100)
    hello(nb_data, pid);
  if (nb_msg == 101)
    attack(nb_data, pid);
  if (nb_msg == 102)
    hit(nb_data, 0);
  if (nb_msg == 103)
    missed(nb_data, 0);
  if (nb_msg == 105)
    win(nb_data);
}

void send_msg(int pid, int msg, int data)
{
  int i;
  char *bit_msg;
  char *bit_data;
  int signum;

  i = 0;
  ATK_CHECKER = 0;
  bit_msg = get_bytestr(msg);
  usleep(1000);
  while (bit_msg[i] != '\0')
  {
    signum = (bit_msg[i] == '1') ? SIGUSR1 : SIGUSR2;
    send_kill(pid, signum);
    i++;
  }
  i = 0;
  bit_data = get_bytestr(data);
  while (bit_data[i] != '\0')
  {
    signum = (bit_data[i] == '1') ? SIGUSR1 : SIGUSR2;
    send_kill(pid, signum);
    i++;
  }
}

void send_kill(int pid, int signum)
{
  kill(pid, signum);
  usleep(1000);
}

void receiver(int signum, siginfo_t *info, void *ptr)
{
  static int i;
  static int nb_msg;
  static int nb_data;
  int bit;

  bit = (signum == SIGUSR1) ? 1 : 0;
  if (i < 8)
    nb_msg += (bit << (7 - i));
  if (i >= 8 && i < 16)
    nb_data += (bit << (15 - i));
  if (i == 15)
  {
    usleep(1000);
    decoder(nb_msg, nb_data, (int)info->si_pid);
    nb_msg = 0;
    nb_data = 0;
    i = 0;
  }
  else
    i++;
}
