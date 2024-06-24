/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_pipe_heredoc_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:35:25 by jmorillo          #+#    #+#             */
/*   Updated: 2023/11/07 20:06:30 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

int	ast_pipe_heredoc_count(t_astree *node)
{
	int				count;
	t_redir_node	*redir;

	count = 0;
	if (!ast_is_pipe(node))
		return (0);
	node = node->child;
	while (node)
	{
		redir = node->cmd->redir;
		while (redir)
		{
			if (redir->type == delimiter_tkn)
				count++;
			redir = redir->next;
		}
		node = node->next;
	}
	return (count);
}
