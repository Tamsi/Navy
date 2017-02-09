/*
** main.c for  in /home/tbesson/maps
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Feb  2 16:20:32 2017 Tamsi Besson
** Last update Fri Feb  3 12:44:55 2017 Tamsi Besson
*/

#include "my.h"

char map[2][8][9] = {
  {
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'}
  },
  {
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'}
  }
};

int coo_to_nb(char *s)
{
  int nb;

  nb = (s[0] - 65) * 8;
  nb += s[1] - 49;
  return (nb);
}

int check_coo(char *s)
{
  if (s[0] >= 'a' && s[0] <= 'h')
    s[0] = s[0] - 32;
  if (s[0] < 'A' && s[0] > 'H')
    return (0);
  if (s[1] < '1' && s[1] > '8')
    return (0);
  if (map[1][s[1] - 49][s[0] - 65] != '.')
    return (0);
  return (1);
}

char *get_bytestr(int nb)
{
  char *bit;
  char *octet;
  int k;
  int j;
  int i;

  j = 8;
  i = 0;
  k = 0;
  octet = malloc (8);
  bit = my_putnbr_base(nb, "01");
  while (j > my_strlen(bit))
  {
    octet[i] = '0';
    i++;
    j--;
  }
  while (bit[k] != '\0')
  {
    octet[i] = bit[k];
    k++;
    i++;
  }
  return (octet);
}

int main(int ac, char **av)
{
  char *s;

  if (my_strcmp(av[1], "-h") == 0)
    return (disp_usage());
  if (ac <= 1)
    return (84);
  handler(SIGUSR1);
  handler(SIGUSR2);
  if (ac == 2)
    init_map(av[1]);
  else
  {
    init_map(av[2]);
    send_msg(my_getnbr(av[1]), HELLO, 0);
  }
  game ();
  return (0);
}
