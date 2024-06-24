/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:36:58 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 20:21:16 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

static t_arg_node	*create_arg_node(char *text);

t_error	ast_add_arg(t_astree *node, char *text)
{
	t_arg_node	*it;
	t_arg_node	*arg;

	if (!node || !node->cmd)
	{
		ft_free((void **)&text);
		return (null_pointer_err);
	}
	arg = create_arg_node(text);
	if (!arg)
	{
		ft_free((void **)&text);
		return (mem_alloc_err);
	}
	if (!node->cmd->args)
		node->cmd->args = arg;
	else
	{
		it = node->cmd->args;
		while (it->next)
			it = it->next;
		it->next = arg;
	}
	return (no_error);
}

static t_arg_node	*create_arg_node(char *text)
{
	t_arg_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_arg_node));
	if (!new_node)
		return (NULL);
	new_node->text = text;
	new_node->next = NULL;
	return (new_node);
}
