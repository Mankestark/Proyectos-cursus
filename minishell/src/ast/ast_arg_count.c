/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_arg_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:36:40 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/27 16:17:04 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

int	ast_arg_count(t_astree *node)
{
	int			count;
	t_arg_node	*arg;

	count = 0;
	if (!ast_is_cmd(node))
		return (-1);
	arg = node->cmd->args;
	while (arg)
	{
		arg = arg->next;
		count++;
	}
	return (count);
}
