/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:40:37 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 00:23:05 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/libft.h"
#include "../../inc/redir.h"

int	check_build(char *cmd)
{
	return (ft_str_cmp(cmd, "export") == 0 || ft_str_cmp(cmd, "cd") == 0
		|| ft_str_cmp(cmd, "exit") == 0 || ft_str_cmp(cmd, "unset") == 0
		|| ft_str_cmp(cmd, "echo") == 0 || ft_str_cmp(cmd, "env") == 0
		|| ft_str_cmp(cmd, "pwd") == 0);
}

static char	*get_exec_path_if_slash(t_executor *exec, t_environ *envs,
		char *cmd)
{
	exec->slash = find_path_slash(cmd);
	if (ft_str_cmp(cmd, "./minishell") == 0)
	{
		if (replace_shlvl(envs, 1) == 1)
			return (NULL);
	}
	cmd = ft_strrchr(cmd, '/');
	exec->path_env = exec->slash;
	return (cmd);
}

static int	get_exec_path_else(t_executor *exec, t_environ *envs)
{
	exec->path_env = evd_get(envs, "PATH");
	if (exec->path_env == NULL)
		return (1);
	return (0);
}

static int	check_cmd(t_astree *tree, t_environ **envs, char *cmd,
		int type_redir)
{
	t_executor	exec;

	exec.args_count = ast_arg_count(tree);
	if (check_stat(cmd) != 0)
		return (2);
	exec.slash = ft_strchr(cmd, '/');
	if (exec.slash != NULL)
		cmd = get_exec_path_if_slash(&exec, *envs, cmd);
	else if (get_exec_path_else(&exec, *envs) == 1 && check_build(cmd) == 0)
		return (1);
	exec.args = args_array(tree->cmd->args, cmd, exec.args_count);
	if (check_build(cmd) == 1 && exec.slash == NULL)
	{
		if (execute_builds(tree, envs, type_redir) == 1)
			return (1);
	}
	else if (check_build(cmd) == 0 && execute_cmd(cmd, exec.path_env, exec.args,
			*envs) == 1)
	{
		ft_free_array(&exec.args);
		return (1);
	}
	ft_free_array(&exec.args);
	ft_free((void **)&exec.slash);
	return (0);
}

int	execute(t_astree *tree, t_environ **envs)
{
	t_execute	ex;
	int			type_redir;
	int			result;

	type_redir = 0;
	result = 0;
	ex.cmd = tree->cmd->text;
	if (!ex.cmd)
		ex.cmd = ":";
	ex.result = 0;
	backup_std(ex.backup_fd);
	if (ast_redir_count(tree) > 0)
		check_redir(tree->cmd, &type_redir, &result);
	if (result != 0)
	{
		restore_std(ex.backup_fd);
		return (result);
	}
	if (ast_is_cmd(tree) != 0)
		ex.result = check_cmd(tree, envs, ex.cmd, type_redir);
	restore_std(ex.backup_fd);
	return (ex.result);
}
