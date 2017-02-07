/*
** my.h for  in /home/tbesson/CPE_2016_getnextline
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sun Jan 15 12:27:22 2017 Tamsi Besson
** Last update Tue Feb  7 00:35:04 2017 Tamsi Besson
*/
#ifndef NAVY
#define NAVY
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define HELLO 100
#define ATTACK 101
#define HIT 102
#define MISSED 103
#define SUNK 104
#define WIN 105

int my_putstr(char *);
int my_strlen(char *);
int my_strncmp(char *, char *, int);
int my_strcmp(char *, char *);
int my_builtins(char *, char **, char **);
int my_exit(char *);
int my_cd(char **, char **);
int my_env(char *, char **);
int my_unsetenv(char **, char **);
char *my_strcat(char *, char *);
char *my_realloc(char *);
char *my_strcpy(char *, char *);
char *my_strcat(char *, char *);
char *getpath(char **, char *);
char *my_putnbr_base(int, char*);
char *get_next_line(const int);
char **my_str_to_wordtab(char *, char);
void sig_handler(int);
void send_msg(int, int, int);
void play(int);
void disp_map(int);

extern char map[2][8][9];
#endif //NAVY
