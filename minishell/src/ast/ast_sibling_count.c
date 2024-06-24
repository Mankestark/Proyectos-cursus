/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_sibling_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:36:39 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/27 16:20:24 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

int	ast_sibling_count(t_astree *node)
{
	int	count;

	count = 0;
	if (!node)
		return (-1);
	node = node->next;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}
