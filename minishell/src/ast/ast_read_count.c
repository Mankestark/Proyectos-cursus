/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_read_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:28:15 by jmorillo          #+#    #+#             */
/*   Updated: 2023/09/17 17:31:44 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

int	ast_read_count(t_astree *node)
{
	int				count;
	t_redir_node	*redir;

	count = 0;
	if (!ast_is_cmd(node))
		return (-1);
	redir = node->cmd->redir;
	while (redir)
	{
		if (redir->type == read_tkn)
			count++;
		redir = redir->next;
	}
	return (count);
}
