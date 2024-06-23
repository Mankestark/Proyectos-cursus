/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:05:50 by mariza            #+#    #+#             */
/*   Updated: 2023/11/09 20:11:52 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"
#include "../../inc/executor.h"
#include "../../inc/redir.h"

void	free_heredoc_content(t_check_heredoc *check)
{
	int	i;

	i = 0;
	while (i < check->delimiter_count)
	{
		free(check->here_split[i]);
		i++;
	}
	check->delimiter_count = 0;
	free(check->here_split);
}

int	add_heredoc(char *content, t_check_heredoc *check)
{
	char	**new_heredoc_contents;
	int		i;

	new_heredoc_contents = (char **)malloc((check->delimiter_count + 1)
			* sizeof(char *));
	if (new_heredoc_contents == NULL)
	{
		print_errors(mem_alloc_err, NULL, 1);
		return (1);
	}
	i = 0;
	while (i < check->delimiter_count)
	{
		new_heredoc_contents[i] = check->here_split[i];
		i++;
	}
	new_heredoc_contents[check->delimiter_count] = ft_strdup(content);
	check->here_split = new_heredoc_contents;
	check->delimiter_count++;
	return (0);
}

int	check_heredoc(t_astree *tree, t_check_heredoc *check)
{
	t_redir_node	*redir;
	int				res;
	int				fd_in;

	res = 0;
	fd_in = 0;
	redir = tree->cmd->redir;
	while (redir)
	{
		if (redir->type == delimiter_tkn)
			res = add_heredoc(redir->text, check);
		redir = redir->next;
	}
	if (check->delimiter_count > 0)
	{
		res = heredoc(fd_in, check);
	}
	return (res);
}
