/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@sutudent.42malaga.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:37:21 by mariza            #+#    #+#             */
/*   Updated: 2023/11/18 14:13:05 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

static void	init_data(int state)
{
	state = 0;
}

static void	update_last_arg(t_main *main)
{
	char		*arg_text;
	t_arg_node	*arg;

	if (ast_arg_count(main->tree))
	{
		arg = main->tree->cmd->args;
		while (arg->next)
			arg = arg->next;
		arg_text = ft_strdup(arg->text);
	}
	else if (main->tree->cmd->text)
		arg_text = ft_strdup(main->tree->cmd->text);
	else
		arg_text = ft_strdup("");
	evd_set(&main->env, ft_strdup("_"), arg_text);
}

static int	process_input(t_main *main)
{
	int	result;

	result = 0;
	if (ft_strlen(main->txt) > 0)
		add_history(main->txt);
	main->error = ast_parse(&main->tree, main->txt, main->env, g_data.state);
	if (main->error != no_error)
	{
		print_errors(main->error, NULL, 0);
		ast_free(&main->tree);
		return (0);
	}
	if (ast_is_cmd(main->tree))
		update_last_arg(main);
	main->result = execute_wrapper(main->tree, &main->env);
	if (ast_is_cmd(main->tree) && ft_str_cmp(main->tree->cmd->text,
			"exit") == 0)
		result = (conchi_exit(main->tree,
					main->tree->cmd->args, main->env) == 1);
	ast_free(&main->tree);
	return (result);
}

int	main(int argc, char **argv, char **envp)
{
	t_main	main;

	(void)argc;
	(void)argv;
	main.txt = NULL;
	main.result = 0;
	init_data(&g_data);
	main.env = evd_load(envp, &main.error);
	signal_handle();
	while (1)
	{
		main.txt = readline("LaCoN$hI> ");
		if (main.txt == NULL)
		{
			state = 0;
			free(main.txt);
			break ;
		}
		if (process_input(&main) == 1)
			break ;
		ft_free((void *)&main.txt);
	}
	evd_free(&main.env);
	free(main.txt);
	return (g_data.state);
}
