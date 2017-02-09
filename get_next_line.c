/*
** main.c for  in /home/tbesson/CPE_2016_getnextline_bootstrap
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Jan  4 15:24:28 2017 Tamsi Besson
** Last update Fri Feb  3 13:43:54 2017 Tamsi Besson
*/

#define READ_SIZE 1
#include "my.h"

char    *my_realloc(char *str)
{
  char  *stock;
  int   i;

  i = 0;
  if ((stock = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
  {
    stock[i] = str[i];
    i++;
  }
  stock[i + 1] = '\0';
  free(str);
  return (stock);
}

char *get_next_line(const int fd)
{
  int z;
  int size;
  static char buffer[READ_SIZE];
  char *s;

  z = 0;
  size = 0;
  if ((s = malloc(sizeof(char))) == NULL)
    return NULL;
  s[0] = '\0';
  while ((size = read(fd, buffer, READ_SIZE)) > 0 && buffer[0] != '\n')
  {
    s = my_realloc(s);
    s[z] = buffer[0];
    z++;
  }
  if (size == 0 && z == 0)
    return (NULL);
  else
    return (s);
}
