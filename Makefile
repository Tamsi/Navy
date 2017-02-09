##
## Makefile for  in /home/tbesson/PSU_2016_my_sokoban/bootstrap
## 
## Made by Tamsi Besson
## Login   <tbesson@epitech.net>
## 
## Started on  Tue Dec  6 14:57:19 2016 Tamsi Besson
## Last update Thu Feb  9 10:56:17 2017 Tamsi Besson
##

SRC=   	 	main.c \
		map.c \
		game.c \
		message.c \
		action.c \
		my_getnbr.c \
		my_put_nbr.c \
		my_putnbr_base.c \
		get_next_line.c \
		my_str_to_wordtab.c \
		my_strfct.c \

NAME	=	navy

OBJ=            $(SRC:.c=.o)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ)


all:            $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
