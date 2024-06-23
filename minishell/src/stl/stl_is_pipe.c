/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_is_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:41:23 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/09 19:19:30 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl.h"

/**
 * @brief	Determines whether the node is of type pipe.
 *
 * @param node	Node of the semantic token list
 * @return int	'1' If pipe. '0' Otherwise. It is also not considered an
 * 				pipe if node is null.
 */
int	stl_is_pipe(t_stlist *node)
{
	if (!node)
		return (0);
	return (node->type == pipe_tkn);
}
