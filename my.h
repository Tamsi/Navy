/*
** my.h for  in /home/tbesson/CPE_2016_getnextline
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sun Jan 15 12:27:22 2017 Tamsi Besson
** Last update Tue Feb  7 02:06:58 2017 Tamsi Besson
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

long	my_getnbr_getsign(char *);
long	my_getnbr_getsign_rank(char *);
long	my_getnbr(char *);
int my_putstr(char *);
int my_strlen(char *);
int my_strcmp(char *, char *);
int check_error(char **, int [], int []);
int init_map(char *);
int coo_to_nb(char *);
int check_coo(char *);
int disp_usage();
char *my_strcat(char *, char *);
char *my_putnbr_base(int, char*);
char *get_next_line(const int);
char *get_bytestr(int);
char **my_str_to_wordtab(char *, char);
void my_put_nbr(int);
void send_msg(int, int, int);
void send_kill(int, int);
void play(int);
void disp_map(int);
void decoder(int, int, int);
void handler(int);
void receiver(int, siginfo_t *, void *);
void play(int);
void game();
void hello(int, int);
void hit(int, int);
void sunk(int);
void win(int);
void missed(int, int);
void attack(int, int);

extern char map[2][8][9];
int SERV_CLIENT;
int ATK_CHECKER;
#endif //NAVY