/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conchi_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:35:01 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 12:02:33 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static bool	is_num(char *cadena)
{
	while (*cadena)
	{
		if (*cadena < '0' || *cadena > '9')
			return (0);
		cadena++;
	}
	return (1);
}

static int	check_double_arg(t_arg_node *args)
{
	if (!is_num(args->text))
	{
		print_errors(0, "only numeric argument\n", 2);
		return (1);
	}
	else
		print_errors(too_many_args, NULL, 1);
	return (0);
}

int	conchi_exit(t_astree *tree, t_arg_node *args, t_environ *envs)
{
	if (ast_arg_count(tree) > 1)
	{
		if (check_double_arg(args) == 1)
			return (1);
	}
	if (replace_shlvl(envs, 1) == 1)
		return (1);
	if (ast_arg_count(tree) == 1)
	{
		if (is_num(args->text))
			g_data.state = ft_atoi(args->text);
		else
			print_errors(0, "only numeric argument\n", 2);
		return (1);
	}
	else if (ast_arg_count(tree) == 0)
	{
		g_data.state = 0;
		return (1);
	}
	return (0);
}
