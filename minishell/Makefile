# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 21:16:40 by dameneze          #+#    #+#              #
#    Updated: 2023/04/25 20:59:06 by dameneze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell
LIBFT			= libft.a

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/

#compilation
CC 				= cc
CF 				= -Wall -Wextra -Werror $(DEBUG)
RDL				= -lreadline
CPPFLAGS += -I ~/.brew/opt/readline/include
LDFLAGS += -L ~/.brew/opt/readline/lib

SRC 			= 	./src/main.c \
					./src/errors.c \
					./src/signals.c \
					./src/clear.c \
					./src/init/input.c \
					./src/init/ft_dup_envp.c \
					./src/init/string_utils.c \
					./src/init/stack_redirects.c \
					./src/init/stack_commands.c \
					./src/init/remove_quotes.c \
					./src/init/expansion.c \
					./src/executions/execute_functions.c \
					./src/executions/ft_run_commands.c \
					./src/executions/ft_redirect.c \
					./src/executions/ft_create_pipes.c \
					./src/executions/ft_close_fds.c \
					./src/executions/ft_dup_fds.c \
					./src/builtins/builtin_match.c \
					./src/builtins/cd.c \
					./src/builtins/echo.c \
					./src/builtins/env.c \
					./src/builtins/exit.c \
					./src/builtins/export.c \
					./src/builtins/pwd.c \
					./src/builtins/unset.c
#common commands
RM 				= rm -rf

#colors
purple= \033[0;35m
#rules
$(NAME):		$(SRC) $(LIBFT_PATH)
				@echo "$(purple)Compilation... PERFECT 🤪🤩"
				@make -C $(LIBFT_PATH) $(LIBFT)
				@$(CC) $(CF) $(SRC) $(LIBS) -L $(LIBFT_PATH) -lft $(RDL) $(CPPFLAGS) $(LDFLAGS) -o $(NAME)

valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes  --track-fds=yes ./minishell
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --suppressions=./minimal.supp --gen-suppressions=all --log-file=leaks_val.log --track-fds=yes ./minishell
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./minishell

all:			$(NAME)

re:				fclean all

clean:
				@make -C $(LIBFT_PATH) clean

fclean:			clean
				@make -C $(LIBFT_PATH) fclean
				@$(RM) $(NAME)

.PHONY:			all clean fclean re
