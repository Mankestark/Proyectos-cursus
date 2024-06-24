/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_is_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:44:22 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/25 19:35:46 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl.h"

/**
 * @brief	Determines whether the node is of type text (command, argument,
 * 			stream/file).
 *
 * @param node	Node of the semantic token list
 * @return int	'1' If it is a text. '0' Otherwise. It is also not
 * 				considered to be text if node is NULL.
 */
int	stl_is_text(t_stlist *node)
{
	if (!node)
		return (0);
	return (node->type == command_tkn
		|| node->type == argument_tkn
		|| node->type == stream_tkn);
}
