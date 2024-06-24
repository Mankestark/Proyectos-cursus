/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:20:30 by mariza            #+#    #+#             */
/*   Updated: 2023/11/08 13:07:20 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "ast.h"
# include "ast_toolkit.h"
# include "builder.h"
# include "data.h"
# include "environ.h"
# include "error.h"
# include "libft.h"
# include "redir.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe_cmd
{
	int			i;
	int			count;
	int			result;
	int			*pipefd;
	int			backup_fd[3];
	int			*pid;
	t_astree	*tree;
	t_environ	*env;
}				t_pipe_cmd;

typedef struct s_executor
{
	char		*cmd;
	char		**args;
	char		*path_env;
	int			args_count;
	char		*slash;
}				t_executor;

typedef struct s_exec_cmd
{
	pid_t		pid;
	int			state;
	char		*path_cmd;
	char		**envs;
	t_error		error;
}				t_exec_cmd;
typedef struct s_exec_array
{
	char		**args;
	int			i;
}				t_exec_array;

typedef struct s_execute
{
	int			backup_fd[3];
	int			result;
	char		*cmd;
}				t_execute;

// Executor
int				execute(t_astree *tree, t_environ **env);
int				execute_cmd(char *cmd, char *path_env, char **args,
					t_environ *envs);
int				check_build(char *cmd);
char			**args_array(t_arg_node *node, char *cmd, int args_count);
char			*find_path_slash(char *cmd);
int				replace_shlvl(t_environ *list, int cmd);
int				execute_wrapper(t_astree *tree, t_environ **envs);
int				handle_commands(t_astree *tree, t_environ **envs,
					t_pipe_cmd *pipe_cmd);
int				file_check(char *cmd);
int				check_stat(char *cmd);
void			handle_here_commands(t_astree *tree, t_environ **envs,
					t_pipe_cmd *pipe_cmd);
int				execute_pipes(t_astree *tree, t_environ **envs);

#endif
