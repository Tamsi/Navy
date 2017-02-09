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
        my_putstr("enemy connected\n\n");
        if (nb_data == 0)
                send_msg(pid, HELLO, 1);
        disp_map(0);
  disp_map(1);
  if (nb_data == 1)
        play(pid);
}

void hit(int nb_data)
{
        int x;
        int y;
        char *s;

        x = nb_data / 8;
        y = nb_data % 8;
        s[0] = x + 65;
        s[1] = y + 49;
        map[1][y][x] = 'x';
        my_putstr(my_strcat(s, ": "));
        my_putstr("hit\n");
}

void missed(int nb_data)
{
        int x;
        int y;
        char *s;

        x = nb_data / 8;
        y = nb_data % 8;
        s[0] = x + 65;
        s[1] = y + 49;
        map[1][y][x] = 'o';
        my_putstr(my_strcat(s, ": "));
        my_putstr("missed\n");
}

void sunk(int nb_data)
{
        printf("player connected");
}

void win(int nb_data)
{
        printf("player connected");
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
        }
        else
        {
                map[0][y][x] = 'o';
                send_msg(pid, MISSED, nb_data);
        }
        disp_map(0);
        disp_map(1);
        play(pid);
}
