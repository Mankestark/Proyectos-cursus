/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conchi_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:37:38 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 23:07:56 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static bool	check_nflag(char *arg)
{
	int		i;
	bool	n_flag;

	n_flag = false;
	i = 0;
	if (arg[i] != '-' || arg[i + 1] != 'n')
		return (n_flag);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = true;
	return (n_flag);
}

static int	check_flag(t_arg_node *args)
{
	char	*text;

	text = args->text;
	if (ft_str_cmp(text, "$?") == 13)
	{
		printf("%d\n", g_data.state);
		g_data.state = 0;
		return (1);
	}
	return (0);
}

static void	print_args(t_arg_node *args)
{
	while (args != NULL)
	{
		ft_putstr_fd(args->text, STDOUT_FILENO);
		args = args->next;
		if (args != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
}

int	conchi_echo(t_arg_node *args, int type_redir)
{
	int	print_newline;

	print_newline = 1;
	if (type_redir != 6)
	{
		if (args == NULL)
		{
			ft_putstr_fd("\n", STDOUT_FILENO);
			return (0);
		}
		while (check_nflag(args->text) == true)
		{
			print_newline = 0;
			if (args->next == NULL)
				return (0);
			args = args->next;
		}
		if (check_flag(args) == 0)
			print_args(args);
		if (print_newline && !(ft_str_cmp(args->text, "$?") == 13))
			ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
