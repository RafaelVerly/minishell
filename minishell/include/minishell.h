/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:29:05 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 20:01:14 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//stds
# include <stdio.h>
# include <stdlib.h>
//readlines
# include <readline/readline.h>
# include <readline/history.h>
//files
# include <fcntl.h>
//unix
# include <unistd.h>
//signals
# include <signal.h>
//Systems
# include <sys/ioctl.h>
# include <sys/wait.h>
//erros
# include <errno.h>
//minishell
# include "../libft/libft.h"
# include "../include/minishell.h"

# define CH_FORBIDDEN " !><()@/.='$;\"ç&|"
# define CWHI	"\x1B[0m"
# define CBLU	"\x1B[34m"
# define RDRI 0
# define RDRII 1
# define RDRO 2
# define RDROO 3

typedef struct s_shell
{
	int		exit_status;
	char	**envp;
}	t_shell;

typedef struct s_match
{
	int		pos;
	int		match;
	char	*value;
}	t_match;

typedef struct s_red
{
	int				type;
	char			*val;
	struct s_red	*prev;
	struct s_red	*next;
	struct s_exec	*exec;
}	t_red;

typedef struct s_exec
{
	int				fd[2];
	int				p_fd[2];
	int				pid;
	struct s_exec	*prev;
	struct s_exec	*next;
	int				err_rd;
	char			**arr_args;
	int				args_size;
	t_red			*reds;
}	t_exec;

//Global
extern t_shell	g_shell;

//Signals
void	sigint_handler(int sig);

//Executions
void	ft_run_commands(t_exec **exec);
void	ft_close_fds(t_exec **exec);
int		ft_create_pipes(t_exec **exec);
void	ft_dup_fds(t_exec **exec);
int		ft_redirect(t_exec **exec, t_red *red);
int		ft_find_function(t_exec *exec);

//Input
void	ft_input_init(char **input);
int		ft_dup_envp(char **envp);
int		ft_check_input(char *str);

//Stacks
void	ft_init_stks(char *str, t_exec **exec);
void	ft_init_red(t_exec *exec, char *str);

//Clear
void	ft_stack_clear(t_exec **exec);
void	ft_arr_clear(char **arr);

//Strings
int		ft_args_size(char *str);
int		ft_sep_redirect(char *str, int i, t_red *red);
int		ft_sep_string(char *str, int i, int type);
int		ft_check_quote(char c, char quote);
int		remove_quotes(char **arg);
void	ft_new_args(t_exec **exec);
int		ft_match(char *var, t_match *match);
int		ft_check_trim(char *str);

// builtins
int		ft_is_builtin(char **arr_args);
int		ft_builtin(t_exec *arr_args);
int		ft_echo(char **arr_exec);
int		ft_export(char *var_env);
int		ft_unset(char *var_env);
int		ft_pwd(void);
int		ft_env(char **args);
int		ft_cd(char *str);
void	ft_exit(char *msg, int code, t_exec **exec);
int		change_pwd(char *old_pwd);

// expansion
int		check_expansion(char *arg, int *i);
int		size_exit_status(int *i);
void	expansion_exit_status(char **new_arg, int *i, int *j);
void	get_expansion(char *arg, char **new_arg, int *i, int *j);
int		iter_env_var(char *arg, int *i, t_match match);
void	build_expansion(t_match *match, char **new_arg, int *j);
#endif
