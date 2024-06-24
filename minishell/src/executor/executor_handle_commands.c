/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_handle_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:56:33 by mariza            #+#    #+#             */
/*   Updated: 2023/11/09 20:03:18 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"
#include "../../inc/executor.h"
#include "../../inc/redir.h"
#include <stdbool.h>

void	handle_here_commands(t_astree *tree, t_environ **envs,
		t_pipe_cmd *pipe_cmd)
{
	t_astree		*current_command;
	t_redir_node	*redir;

	current_command = tree;
	while (current_command != NULL)
	{
		redir = current_command->cmd->redir;
		while (redir != NULL)
		{
			if (redir->type == delimiter_tkn)
			{
				handle_commands(current_command, envs, pipe_cmd);
				break ;
			}
			redir = redir->next;
		}
		current_command = current_command->next;
	}
}

int	handle_commands(t_astree *tree, t_environ **envs, t_pipe_cmd *pipe_cmd)
{
	t_check_heredoc	check;

	check.delimiter_count = 0;
	check.here_split = NULL;
	backup_std(pipe_cmd->backup_fd);
	if (ast_redir_count(tree) > 0)
		pipe_cmd->result = check_heredoc(tree, &check);
	if (ast_is_cmd(tree) && ast_pipe_heredoc_count(tree) == 0)
	{
		pipe_cmd->result = execute(tree, envs);
		restore_std(pipe_cmd->backup_fd);
		return (pipe_cmd->result);
	}
	return (0);
}
