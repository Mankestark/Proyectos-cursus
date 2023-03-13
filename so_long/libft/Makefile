# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariza <mariza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 20:07:15 by mariza            #+#    #+#              #
#    Updated: 2022/11/12 18:08:54 by mariza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_itoa ft_numbers ft_printf ft_strstr ft_gnl ft_strcpy_gnl ft_words ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_strmapi ft_striteri ft_split ft_strchr ft_strdup ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper

OBJS = $(FILES:%=%.o)


CFILES = $(FILES:%=%.c)

NAME = libft.a

LIB = libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)


$(NAME): 
	$(CC) $(CFLAGS) -c $(CFILES) -I./
	ar -rc $(NAME) $(OBJS)


clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




