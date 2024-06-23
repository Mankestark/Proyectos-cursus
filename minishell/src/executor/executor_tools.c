/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:30:13 by mariza            #+#    #+#             */
/*   Updated: 2023/11/09 20:09:51 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"
#include "../../inc/executor.h"
#include "../../inc/libft.h"

char	**args_array(t_arg_node *node, char *cmd, int args_count)
{
	t_exec_array	exec;

	(void)cmd;
	if (args_count < 0)
		return (NULL);
	exec.args = (char **)ft_calloc((args_count + 2), sizeof(char *));
	if (exec.args == NULL)
	{
		print_errors(mem_alloc_err, NULL, 1);
		return (NULL);
	}
	exec.args[0] = ft_strdup(cmd);
	exec.i = 1;
	while (node != NULL && exec.i <= args_count)
	{
		exec.args[exec.i] = ft_strdup(node->text);
		node = node->next;
		exec.i++;
	}
	exec.args[exec.i] = NULL;
	return (exec.args);
}

char	*find_path_slash(char *cmd)
{
	const char	*last_slash;
	char		*path;
	size_t		len;

	last_slash = ft_strrchr(cmd, '/');
	if (last_slash != NULL)
	{
		len = last_slash - cmd;
		path = (char *)malloc(len + 1);
		if (path != NULL)
		{
			ft_strncpy(path, cmd, len);
			path[len] = '\0';
			return (path);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

int	replace_shlvl(t_environ *envs, int cmd)
{
	int		level;
	char	*level_char;

	level_char = NULL;
	level = ft_atoi(evd_get(envs, "SHLVL"));
	if (cmd == 1)
	{
		level++;
		level_char = ft_itoa(level);
		if (evd_set(&envs, ft_strdup("SHLVL"), ft_strdup(level_char)) != 0)
			return (1);
	}
	else if (cmd == 0)
	{
		level--;
		level_char = ft_itoa(level);
		if (evd_set(&envs, ft_strdup("SHLVL"), ft_strdup(level_char)) != 0)
			return (1);
	}
	free(level_char);
	return (0);
}

int	file_check(char *cmd)
{
	struct stat	buf;

	if (stat(cmd, &buf) == -1)
	{
		ft_putstr_fd("not directory\n", 2);
		g_data.state = 127;
		return (1);
	}
	else if (S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("is directory\n", 2);
		g_data.state = 126;
		return (1);
	}
	else if ((buf.st_mode & S_IXUSR) == 0)
	{
		ft_putstr_fd("not permission \n", 2);
		g_data.state = 126;
		return (1);
	}
	return (0);
}

int	check_stat(char *cmd)
{
	if (ft_strchr(cmd, '.') || ft_strchr(cmd, '/'))
	{
		if (file_check(cmd) != 0)
			return (1);
	}
	return (0);
}
