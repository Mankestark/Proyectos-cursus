/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:44:34 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 23:03:38 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static char	*find_cmd(char *cmd, char *path)
{
	size_t		cmd_len;
	char		*fin_dir;
	size_t		dir_len;
	static char	p_cmd[256];

	cmd_len = ft_strlen(cmd);
	while (*path)
	{
		fin_dir = ft_strchr(path, ':');
		if (fin_dir == NULL)
			fin_dir = path + ft_strlen(path);
		dir_len = fin_dir - path;
		if (dir_len + cmd_len + 2 <= sizeof(p_cmd))
		{
			ft_strncpy(p_cmd, path, dir_len);
			p_cmd[dir_len] = '/';
			ft_strncpy(p_cmd + dir_len + 1, cmd, sizeof(p_cmd) - dir_len - 1);
			if (access(p_cmd, X_OK) == 0)
				return (p_cmd);
		}
		if (!(*fin_dir == ':'))
			break ;
		path = fin_dir + 1;
	}
	return (NULL);
}

int	execute_cmd(char *cmd, char *path_env, char **args, t_environ *envp)
{
	t_exec_cmd	exec;

	exec.envs = evd_save(envp, &exec.error);
	exec.path_cmd = find_cmd(cmd, path_env);
	if ((exec.path_cmd == NULL && ft_str_cmp(cmd, ":") != 0) || ft_str_cmp(cmd,
			"") == 0 || ft_str_cmp(cmd, "''") == 0)
	{
		ft_free_array(&exec.envs);
		print_errors(not_cmd, NULL, 127);
		return (0);
	}
	exec.state = 0;
	exec.pid = fork();
	if (exec.pid == 0)
	{
		execve(exec.path_cmd, args, exec.envs);
		exit(1);
	}
	else if (exec.pid == -1)
		return (1);
	ft_free_array(&exec.envs);
	waitpid(exec.pid, &exec.state, 0);
	if (WIFEXITED(exec.state))
		g_data.state = WEXITSTATUS(exec.state);
	return (0);
}
