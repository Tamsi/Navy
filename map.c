/*
** map.c for  in /home/tbesson/projet_psu/PSU_2016_navy
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue Feb  7 14:51:42 2017 Tamsi Besson
** Last update Tue Feb  7 14:51:43 2017 Tamsi Besson
*/

#include "my.h"

int check_error(char **pos_tab, int posA[], int posB[])
{
  if (pos_tab[0][0] < '2' || pos_tab[0][0] > '5')
    return (84);
  if ((pos_tab[1][0] < 'A' || pos_tab[1][0] > 'H')
   || (pos_tab[2][0] < 'A' || pos_tab[2][0] > 'H'))
    return (84);
  if ((pos_tab[1][1] < '1' || pos_tab[1][1] > '8')
   || (pos_tab[2][1] < '1' || pos_tab[2][1] > '8'))
    return (84);
  if ((pos_tab[1][0] != pos_tab[2][0]) && (pos_tab[1][1] != pos_tab[2][1]))
    return (84);
  if ((posB[0] - posA[0] != pos_tab[0][0] - 49)
   && (posB[1] - posA[1] != pos_tab[0][0] - 49))
    return (84);
  return (0);
}

void set_map(int posA[], int posB[], char **pos_tab)
{
  int i;

  i = posA[1];
  if (posA[0] == posB[0])
    while (i <= posB[1])
    {
      map[0][i][posA[0]] = pos_tab[0][0];
      i++;
    }
  i = posA[0];
  if (posA[1] == posB[1])
    while (i <= posB[0])
    {
      map[0][posA[1]][i] = pos_tab[0][0];
      i++;
    }
}

int init_map(char *str)
{
  char *s;
  char **pos_tab;
  int fd;
  int posA[2];
  int posB[2];

  fd = open (str, O_RDONLY);
  if (fd == -1)
    return (84);
  while (s = get_next_line (fd))
  {
    pos_tab = my_str_to_wordtab (s, ':');
    posA[0] = pos_tab[1][0] - 65;
    posA[1] = pos_tab[1][1] - 49;
    posB[0] = pos_tab[2][0] - 65;
    posB[1] = pos_tab[2][1] - 49;
    if (check_error(pos_tab, posA, posB) != 0)
      return (84);
    set_map(posA, posB, pos_tab);
  }
  return (0);
}

void disp_map(int id)
{
  int i;
  int j;

  if (id == 0)
    my_putstr("my positions:\n");
  else
    my_putstr("enemy's positions:\n");
  my_putstr(" |A B C D E F G H\n");
  my_putstr("-+---------------\n");
  i = 0;
  while (i < 8)
  {
    j = 0;
    my_put_nbr(i + 1);
    my_putstr("|");
    while (map[id][i][j])
    {
      write (1, &map[id][i][j], 1);
      write (1, " ", 1);
      j++;
    }
    my_putstr("\n");
    i++;
  }
  my_putstr("\n");
}