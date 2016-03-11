##
## Makefile for Neural Color in /home/salnik_a/pers/NN_Color
##
## Made by alexis salnikoff
## Login   <salnik_a@epitech.net>
##
## Started on Fri Mar 11 12:47:07 2016 alexis salnikoff
## Last update Fri Mar 11 16:31:31 2016 alexis salnikoff
##

NAME	= NeuralColor

SRC	= main.cpp \
	Neural_Network.cpp \
	Population.cpp \
	ColorDiff.cpp		\
	Utils.cpp \

OBJ	= $(SRC:.cpp=.o)

CPP	= g++

##CPPFLAGS	= -W -Wall -Werror

LIB = -lsfml-graphics -lsfml-window -lsfml-system

RM	= rm -f

$(NAME): $(OBJ)
	$(CPP) -g -o $(NAME) $(OBJ) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
