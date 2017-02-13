/*
** action.c for  in /home/tbesson/projet_psu/PSU_2016_minishell1/maps
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Mon Feb  6 12:26:04 2017 Tamsi Besson
** Last update Mon Feb  6 12:26:06 2017 Tamsi Besson
*/

#include "my.h"

void hello(int nb_data, int pid)
{
  if (SERV_CLIENT == 1)
    my_putstr("enemy connected\n\n");
  else
    my_putstr("successfully connected\n\n");
  disp_map(0);
  disp_map(1);
  if (nb_data == 0)
  {
    send_msg(pid, HELLO, 1);
    play(pid);
  }
  else
    my_putstr("waiting for enemy's attack...\n");
  ATK_CHECKER = 0;
}

void hit(int nb_data, int c)
{
  int x;
  int y;
  char s[2];

  x = nb_data / 8;
  y = nb_data % 8;
  s[0] = x + 65;
  s[1] = y + 49;
  s[2] = '\0';
  my_putstr(s);
  my_putstr(": hit\n\n");
  if (c == 0)
  {
    map[1][y][x] = 'x';
    disp_map(0);
    disp_map(1);
  }
  ATK_CHECKER = 1;
}

void missed(int nb_data, int c)
{
  int x;
  int y;
  char s[2];

  x = nb_data / 8;
  y = nb_data % 8;
  s[0] = x + 65;
  s[1] = y + 49;
  s[2] = '\0';
  my_putstr(s);
  my_putstr(": missed\n\n");
  if (c == 0)
  {
    map[1][y][x] = 'o';
    disp_map(0);
    disp_map(1);
  }
  ATK_CHECKER = 1;
}

void win(int nb_data)
{
  write (1, "NON\n", 4);
}

void attack(int nb_data, int pid)
{
  int x;
  int y;

  x = nb_data / 8;
  y = nb_data % 8;
  if (map[0][y][x] != '.')
  {
    map[0][y][x] = 'x';
    send_msg(pid, HIT, nb_data);
    hit(nb_data, 1);
  }
  else
  {
    map[0][y][x] = 'o';
    send_msg(pid, MISSED, nb_data);
    missed(nb_data, 1);
  }
  disp_map(0);
  disp_map(1);
  play(pid);
}
