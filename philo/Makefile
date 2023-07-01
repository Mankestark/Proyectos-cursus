# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariza <mariza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 12:33:32 by mariza            #+#    #+#              #
#    Updated: 2023/06/28 12:33:33 by mariza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -pthread
SRC = philo.c checks.c kill_phil.c times.c lunch.c start.c printing.c errors.c
OBJ = $(SRC:.c=.o)
INC = ./include/
LINKS = -I $(INC) 
all : $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LINKS)  

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean