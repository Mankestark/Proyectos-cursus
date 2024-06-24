/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_sibling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:59:48 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/23 19:55:41 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

t_error	ast_add_sibling(t_astree *node, t_astree *sibling)
{
	if (!node)
	{
		ast_free(&sibling);
		return (null_pointer_err);
	}
	if (!sibling)
		return (null_pointer_err);
	while (node->next)
		node = node->next;
	node->next = sibling;
	return (no_error);
}
