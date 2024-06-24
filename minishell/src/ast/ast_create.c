/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:11:16 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 20:28:38 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

static t_cmd_node	*create_command_node(void);

t_astree	*ast_create(int type, t_error *error)
{
	t_astree	*new_node;

	new_node = ft_calloc(1, sizeof(t_astree));
	if (!new_node)
	{
		*error = mem_alloc_err;
		return (NULL);
	}
	new_node->type = type;
	if (type == command_tkn)
	{
		new_node->cmd = create_command_node();
		if (!new_node->cmd)
		{
			*error = mem_alloc_err;
			ast_free (&new_node);
			return (NULL);
		}
	}
	else
		new_node->cmd = NULL;
	new_node->next = NULL;
	new_node->child = NULL;
	return (new_node);
}

static t_cmd_node	*create_command_node(void)
{
	t_cmd_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_cmd_node));
	if (!new_node)
		return (NULL);
	new_node->text = NULL;
	new_node->args = NULL;
	new_node->redir = NULL;
	return (new_node);
}
