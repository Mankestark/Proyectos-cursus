/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:22:33 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/28 16:56:55 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static t_error	expand_text(char **text, t_environ *environ, int return_code);
static t_error	expand_delim(char **text);
static t_error	expand_arguments(t_arg_node *arg, t_environ *environ,
					int return_code);
static t_error	expand_redirections(t_redir_node *redir, t_environ *environ,
					int return_code);

t_error	ast_expand(t_astree *tree, t_environ *environ, int return_code)
{
	t_error	error;

	if (!tree)
		return (no_error);
	if (ast_is_cmd(tree))
	{
		error = expand_text(&tree->cmd->text, environ, return_code);
		if (error)
			return (error);
		error = expand_arguments(tree->cmd->args, environ, return_code);
		if (error)
			return (error);
		error = expand_redirections(tree->cmd->redir, environ, return_code);
		if (error)
			return (error);
	}
	error = ast_expand(tree->next, environ, return_code);
	if (error)
		return (error);
	error = ast_expand(tree->child, environ, return_code);
	return (error);
}

static t_error	expand_text(char **text, t_environ *environ, int return_code)
{
	int		text_len;
	char	*text_value;

	if (!*text)
		return (no_error);
	text_len = ast_text_len(*text, environ, return_code);
	text_value = ast_text_value(*text, text_len, environ, return_code);
	ft_free((void **)text);
	*text = text_value;
	return (no_error);
}

static t_error	expand_delim(char **text)
{
	int		text_len;
	char	*text_value;

	if (!*text)
		return (no_error);
	text_len = ast_delim_len(*text);
	text_value = ast_delim_value(*text, text_len);
	ft_free((void **)text);
	*text = text_value;
	return (no_error);
}

static t_error	expand_arguments(t_arg_node *arg, t_environ *environ,
	int return_code)
{
	t_error	error;

	if (!arg)
		return (no_error);
	error = expand_text(&arg->text, environ, return_code);
	if (error)
		return (error);
	error = expand_arguments(arg->next, environ, return_code);
	return (error);
}

static t_error	expand_redirections(t_redir_node *redir, t_environ *environ,
	int return_code)
{
	t_error	error;

	if (!redir)
		return (no_error);
	if (redir->type == delimiter_tkn)
		error = expand_delim(&redir->text);
	else
		error = expand_text(&redir->text, environ, return_code);
	if (error)
		return (error);
	error = expand_redirections(redir->next, environ, return_code);
	return (error);
}
