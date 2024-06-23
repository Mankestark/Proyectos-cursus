/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_is_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:37:46 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/25 19:35:23 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl.h"

/**
 * @brief	Determines whether the node is of type redirection.
 *
 * @param node	Node of the semantic token list
 * @return int	'1' If it is a redirection operator. '0' Otherwise. Also not
 * 				considered an redirection if node is NULL.
 */
int	stl_is_redir(t_stlist *node)
{
	if (!node)
		return (0);
	return (node->type == write_tkn
		|| node->type == append_tkn
		|| node->type == read_tkn
		|| node->type == delimiter_tkn);
}
