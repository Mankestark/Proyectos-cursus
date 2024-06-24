/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:56:00 by jmorillo          #+#    #+#             */
/*   Updated: 2023/09/16 14:54:34 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static t_error	add_command_node(t_astree **root, t_stlist **list);
static t_error	add_pipe_node(t_astree **root);

t_error	ast_generate(t_astree **tree, t_stlist *list)
{
	t_error	error;

	error = no_error;
	*tree = NULL;
	while (list)
	{
		if (stl_is_text(list) || stl_is_redir(list))
			error = add_command_node(tree, &list);
		else if (list->type == pipe_tkn)
			error = add_pipe_node(tree);
		else
			error = operator_err;
		if (error)
		{
			ast_free(tree);
			return (error);
		}
		list = list->next;
	}
	return (error);
}

static t_error	add_command_node(t_astree **root, t_stlist **list)
{
	t_error		error;
	t_astree	*new_node;

	error = ast_new_command_node(&new_node, list);
	if (!(*root))
		*root = new_node;
	else if ((*root)->type == pipe_tkn)
		error = ast_add_child(*root, new_node);
	return (error);
}

static t_error	add_pipe_node(t_astree **root)
{
	t_error		error;
	t_astree	*new_node;

	error = no_error;
	if (!(*root))
		*root = ast_create(pipe_tkn, &error);
	else if ((*root)->type == command_tkn)
	{
		new_node = ast_create(pipe_tkn, &error);
		if (error)
			return (error);
		error = ast_add_child(new_node, *root);
		if (error)
			return (error);
		*root = new_node;
	}
	return (error);
}
