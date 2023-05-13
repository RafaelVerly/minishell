# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dameneze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 00:16:28 by dameneze          #+#    #+#              #
#    Updated: 2022/11/19 19:57:49 by dameneze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rc
LIB1		= ranlib
RM			= rm -f

INCS		= libft.h
SRCS		= ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c \
				ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c \
				ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c \
				ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c \
				ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memchr.c \
				ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c get_next_line.c \
				ft_unsigned_itoa.c ft_to_hexa.c ft_printf.c

OBJS		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) $(INCS)
			@$(LIB)	$(NAME) $(OBJS)
			@$(LIB1)	$(NAME)

.c.o:
			@$(CC) $(CFLAGS) -include $(INCS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
