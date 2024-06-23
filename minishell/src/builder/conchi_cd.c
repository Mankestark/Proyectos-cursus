/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conchi_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:12:26 by mariza            #+#    #+#             */
/*   Updated: 2023/09/28 12:56:35 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static char	*get_pwd(char *buf)
{
	size_t	size;
	char	*buffer;

	(void)buf;
	size = 256;
	buffer = malloc((size_t)size);
	getcwd(buffer, size);
	return (buffer);
}

static int	replace_pwd(t_environ *list, char *current_pwd, char *old_pwd)
{
	if (evd_set(&list, ft_strdup("PWD"), ft_strdup(current_pwd)) != 0)
		return (1);
	if (evd_set(&list, ft_strdup("OLDPWD"), ft_strdup(old_pwd)) != 0)
		return (1);
	return (0);
}

int	conchi_cd(t_arg_node *args, t_environ *env)
{
	char		*current_pwd;
	char		*old_pwd;
	char		*buf;
	char		*path_to_change;
	t_environ	*list;

	list = env;
	buf = NULL;
	old_pwd = get_pwd(buf);
	if (args != NULL)
		path_to_change = args->text;
	else
		path_to_change = evd_get(list, "HOME");
	if (chdir(path_to_change) == -1)
	{
		print_errors(not_file, NULL, 1);
		return (1);
	}
	current_pwd = get_pwd(buf);
	if (replace_pwd(list, current_pwd, old_pwd) == 0)
		return (0);
	print_errors(not_file, NULL, 1);
	free(old_pwd);
	free(current_pwd);
	return (1);
}
