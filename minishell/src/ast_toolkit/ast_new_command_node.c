/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new_command_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:11:18 by jmorillo          #+#    #+#             */
/*   Updated: 2023/09/16 15:09:29 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static t_error	add_argument(t_astree *node, char *token);
static t_error	add_redirection(t_astree *node, t_stlist **list);
static t_error	add_command_text(t_astree *node, char *token);
static t_error	free_and_error(t_astree **node, t_error error);

/**
 * @brief
 *
 * @param root
 * @param list
 * @return t_error
 */
t_error	ast_new_command_node(t_astree **new_node, t_stlist **list)
{
	t_stlist	*last_token;
	t_error		error;

	error = no_error;
	*new_node = ast_create(command_tkn, &error);
	if (error)
		return (error);
	last_token = *list;
	while ((*list) && (stl_is_text(*list) || stl_is_redir(*list)))
	{
		if ((*list)->type == command_tkn)
			add_command_text(*new_node, (*list)->token);
		else if ((*list)->type == argument_tkn)
			error = add_argument(*new_node, (*list)->token);
		else if (stl_is_redir(*list))
			error = add_redirection(*new_node, list);
		if (error)
			free_and_error(new_node, error);
		last_token = *list;
		*list = (*list)->next;
	}
	*list = last_token;
	return (error);
}

static t_error	add_command_text(t_astree *node, char *token)
{
	char	*command;

	command = ft_strdup(token);
	if (!command)
		return (mem_alloc_err);
	node->cmd->text = command;
	return (no_error);
}

static t_error	add_argument(t_astree *node, char *token)
{
	char	*argument;
	t_error	error;

	argument = ft_strdup(token);
	if (!argument)
		error = mem_alloc_err;
	else
		error = ast_add_arg(node, argument);
	return (error);
}

static t_error	add_redirection(t_astree *node, t_stlist **list)
{
	t_error	error;
	char	*stream;

	if (!(*list)->next || (*list)->next->type != stream_tkn)
		error = syntax_err;
	else
	{
		stream = ft_strdup((*list)->next->token);
		if (!stream)
			error = mem_alloc_err;
		else
			error = ast_add_redir(node, (*list)->type, stream);
		(*list) = (*list)->next;
	}
	return (error);
}

static t_error	free_and_error(t_astree **node, t_error error)
{
	ast_free(node);
	return (error);
}
