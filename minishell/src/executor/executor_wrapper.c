/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_wrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:56:55 by jmorillo          #+#    #+#             */
/*   Updated: 2023/11/09 21:52:31 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"
#include "../../inc/executor.h"
#include "../../inc/redir.h"

static int	init_pipe_cmd(t_pipe_cmd *pipe_cmd, t_astree *tree,
				t_environ **env);
static void	close_pipes(int *pipes, int cmd_count, t_pipe_cmd *pipe_cmd);
static void	init_pipes(t_pipe_cmd *pipe_cmd_ptr);
static void	handle_heredocs(t_astree *tree, t_environ **envs,
				t_pipe_cmd *pipe_cmd);

int	execute_wrapper(t_astree *tree, t_environ **envs)
{
	t_pipe_cmd	pipe_cmd;

	if (init_pipe_cmd(&pipe_cmd, tree, envs) == 0)
		return (pipe_cmd.result);
	handle_heredocs(tree, envs, &pipe_cmd);
	while (++pipe_cmd.i < pipe_cmd.count)
	{
		pipe_cmd.pid[pipe_cmd.i] = fork();
		if (pipe_cmd.pid[pipe_cmd.i] == -1)
			print_error_and_exit(null_pointer_err, 1);
		else if (pipe_cmd.pid[pipe_cmd.i] == 0)
		{
			if (pipe_cmd.i > 0)
				dup2(pipe_cmd.pipefd[pipe_cmd.i * 2 - 2], STDIN_FILENO);
			if (pipe_cmd.i < pipe_cmd.count - 1)
				dup2(pipe_cmd.pipefd[pipe_cmd.i * 2 + 1], STDOUT_FILENO);
			close_pipes(pipe_cmd.pipefd, pipe_cmd.count, &pipe_cmd);
			if (pipe_cmd.tree->type != delimiter_tkn)
				exit(execute(pipe_cmd.tree, envs));
		}
		pipe_cmd.tree = pipe_cmd.tree->next;
	}
	close_pipes(pipe_cmd.pipefd, pipe_cmd.count, &pipe_cmd);
	return (0);
}

static int	init_pipe_cmd(t_pipe_cmd *pipe_cmd, t_astree *tree, t_environ **env)
{
	pipe_cmd->result = handle_commands(tree, env, pipe_cmd);
	pipe_cmd->i = -1;
	pipe_cmd->pipefd = NULL;
	pipe_cmd->count = ast_child_count(tree);
	if (pipe_cmd->count <= 0)
		return (0);
	pipe_cmd->pid = malloc(pipe_cmd->count * sizeof(int));
	if (!pipe_cmd->pid)
	{
		print_errors(mem_alloc_err, NULL, 1);
		exit(1);
	}
	init_pipes(pipe_cmd);
	pipe_cmd->tree = tree->child;
	pipe_cmd->env = *env;
	return (1);
}

static void	handle_heredocs(t_astree *tree, t_environ **envs,
				t_pipe_cmd *pipe_cmd)
{
	int			i;
	t_astree	*heredoc_cmd;

	heredoc_cmd = tree->child;
	i = ast_pipe_heredoc_count(pipe_cmd->tree);
	if (heredoc_cmd != NULL)
	{
		while (heredoc_cmd != NULL && i >= 0)
		{
			handle_here_commands(heredoc_cmd, envs, pipe_cmd);
			heredoc_cmd = heredoc_cmd->next;
			i--;
		}
	}
}

static void	close_pipes(int *pipes, int cmd_count, t_pipe_cmd *pipe_cmd)
{
	int	i;
	int	status;

	i = 0;
	while (i < (cmd_count - 1) * 2)
	{
		close(pipes[i]);
		i++;
	}
	i = 0;
	while (i < cmd_count)
	{
		waitpid(pipe_cmd->pid[i], &status, 0);
		g_data.state = WEXITSTATUS(status);
		i++;
	}
	free(pipes);
}

static void	init_pipes(t_pipe_cmd *pipe_cmd)
{
	int	i;
	int	count;

	count = pipe_cmd->count - 1;
	pipe_cmd->pipefd = malloc(2 * count * sizeof(int));
	if (!pipe_cmd->pipefd)
	{
		print_errors(mem_alloc_err, NULL, 1);
		exit(1);
	}
	i = 0;
	while (i < count)
	{
		if (pipe(&pipe_cmd->pipefd[i * 2]) == -1)
			print_error_and_exit(null_pointer_err, 1);
		i++;
	}
}
