/*
** my_str_to_wordtab.c for  in /home/tbesson/projet_psu/PSU_2016_minishell1
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Mon Jan 16 17:29:37 2017 Tamsi Besson
** Last update Fri Feb  3 13:43:26 2017 Tamsi Besson
*/

#include "my.h"

int word_count(char *str, char c)
{
  int   i;
  int   cpt;
  char  car_prec;

  i = 0;
  cpt = 0;
  car_prec = c;
  while (str[i] != '\0')
    {
      if ((car_prec == c) && (str[i] != c))
        {
          cpt++;
        }
      car_prec = str[i];
      i++;
    }
  return (cpt);
}

char    *my_strncpy(char *str, char *dest, int debut, char c)
{
  int   i;

  i = 0;
  while ((str[debut] != c) && (str[debut] != '\0'))
    {
      dest[i] = str[debut];
      debut++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int count(char *str, int debut, char c)
{
  int   i;

  i = 0;
  while ((str[debut] != c) && (str[debut] != '\0'))
    {
      debut++;
      i++;
    }
  return (i);
}

char    **my_str_to_wordtab(char *str, char c)
{
  int   i;
  int   j;
  char  car_prec;
  char  **tab;

  i = 0;
  j = 0;
  tab = malloc((word_count(str, c) + 1) * sizeof(tab));
  car_prec = c;
  while (str[i] != '\0')
    {
      if ((car_prec == c) && (str[i] != c))
        {
          tab[j] = malloc((count(str, i, c) + 1) * sizeof(**tab));
          my_strncpy(str, tab[j], i, c);
          j++;
        }
      car_prec = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
