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
    if (posA[0] == posB[0])
      for (int i = posA[1]; i <= posB[1]; i++)
        map[0][i][posA[0]] = pos_tab[0][0];
    if (posA[1] == posB[1])
      for (int i = posA[0]; i <= posB[0]; i++)
        map[0][posA[1]][i] = pos_tab[0][0];
  }
  return (0);
}

void disp_map(int id)
{
  int i;
  int j;
  int y;
  if (id == 0)
    printf("my positions:\n");
  else
    printf("enemy's positions:\n");
  printf(" |A B C D E F G H\n");
  printf("-+---------------\n");
  i = 0;
  y = 1;
  while (i < 8)
  {
    j = 0;
    printf("%i|", y);
    while (map[id][i][j])
    {
      printf("%c ", map[id][i][j]);
      j++;
    }
    printf("\n");
    y++;
    i++;
  }
  my_putstr("\n");
}