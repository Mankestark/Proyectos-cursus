/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:36:20 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 11:08:29 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static int	check_export(t_astree *tree, t_environ **env)
{
	int	result;

	result = 0;
	if (ast_arg_count(tree) == 0)
		result = conchi_env(*env);
	else
		result = conchi_export(tree->cmd->args, env);
	return (result);
}

static int	check_env(t_astree *tree, t_environ *env)
{
	int	result;

	result = 0;
	if (ast_arg_count(tree) == 0)
		result = conchi_env(env);
	else
		print_errors(not_file, NULL, 127);
	return (result);
}

int	execute_builds(t_astree *tree, t_environ **env, int type_redir)
{
	int	result;

	result = 0;
	if (tree->cmd->text == NULL)
		return (result);
	else if (ft_str_cmp(tree->cmd->text, "cd") == 0)
		result = conchi_cd(tree->cmd->args, *env);
	else if (ft_str_cmp(tree->cmd->text, "echo") == 0)
		result = conchi_echo(tree->cmd->args, type_redir);
	else if (ft_str_cmp(tree->cmd->text, "env") == 0)
		result = check_env(tree, *env);
	else if (ft_str_cmp(tree->cmd->text, "export") == 0)
		result = check_export(tree, env);
	else if (ft_str_cmp(tree->cmd->text, "pwd") == 0)
		result = conchi_pwd(*env);
	else if (ft_str_cmp(tree->cmd->text, "unset") == 0
		&& (ast_arg_count(tree) != 0))
		result = conchi_unset(tree->cmd->args, env);
	return (result);
}
