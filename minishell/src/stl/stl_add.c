/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:36:11 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 14:36:35 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl.h"

static t_error	create_node(t_stlist **node, char *token, t_tkn_type type);

/**
 * @brief	Creates and adds a new node to the end of the list. If the list does
 * 			not exist, the list is the new node itself. If the list exists, the
 * 			new node is append to the end of the list.
 *
 * @param list		List of semantic tokens
 * @param token		Text of the token ('char *'). It is the same memory
 * 					address that is passed as as argument: no copy is made.
 * @param type		Identifier of the token type ('t_tkn_type').
 * @return t_error	The error code. If no error ocurrs, then returns 'no_error'.
 *
 */
t_error	stl_add(t_stlist **list, char *token, t_tkn_type type)
{
	t_stlist	*iter;
	t_stlist	*new_node;
	t_error		error;

	if (!list)
		return (null_pointer_err);
	error = create_node(&new_node, token, type);
	if (error)
		return (error);
	if (!(*list))
		*list = new_node;
	else
	{
		iter = *list;
		while (iter->next)
			iter = iter->next;
		iter->next = new_node;
	}
	return (no_error);
}

static t_error	create_node(t_stlist **node, char *token, t_tkn_type type)
{
	if (!token)
		return (null_pointer_err);
	*node = ft_calloc(1, sizeof(t_stlist));
	if (!(*node))
		return (mem_alloc_err);
	(*node)->token = token;
	(*node)->type = type;
	(*node)->next = NULL;
	return (no_error);
}
