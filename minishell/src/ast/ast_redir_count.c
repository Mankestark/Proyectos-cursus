/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_redir_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:36:38 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/30 12:07:15 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

int	ast_redir_count(t_astree *node)
{
	int				count;
	t_redir_node	*redir;

	count = 0;
	if (!ast_is_cmd(node))
		return (-1);
	redir = node->cmd->redir;
	while (redir)
	{
		redir = redir->next;
		count++;
	}
	return (count);
}
