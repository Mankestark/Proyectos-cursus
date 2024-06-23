/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:36:55 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 20:21:37 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

static t_redir_node	*create_redir_node(int type, char *text);

t_error	ast_add_redir(t_astree *node, int type, char *text)
{
	t_redir_node	*it;
	t_redir_node	*redir;

	if (!node || !node->cmd)
	{
		ft_free((void **)&text);
		return (null_pointer_err);
	}
	redir = create_redir_node(type, text);
	if (!redir)
	{
		ft_free((void **)&text);
		return (mem_alloc_err);
	}
	if (!node->cmd->redir)
		node->cmd->redir = redir;
	else
	{
		it = node->cmd->redir;
		while (it->next)
			it = it->next;
		it->next = redir;
	}
	return (no_error);
}

static t_redir_node	*create_redir_node(int type, char *text)
{
	t_redir_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_redir_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	new_node->text = text;
	new_node->next = NULL;
	return (new_node);
}
