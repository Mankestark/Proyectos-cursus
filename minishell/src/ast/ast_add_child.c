/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:57:44 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/23 19:55:21 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

t_error	ast_add_child(t_astree *node, t_astree *child)
{
	if (!node)
	{
		ast_free(&child);
		return (null_pointer_err);
	}
	if (!child)
		return (null_pointer_err);
	if (!node->child)
		node->child = child;
	else
	{
		node = node->child;
		while (node->next)
			node = node->next;
		node->next = child;
	}
	return (no_error);
}
