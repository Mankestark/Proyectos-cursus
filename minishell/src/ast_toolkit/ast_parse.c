/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:07:54 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/21 10:12:08 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

/**
 * @brief	Parses the input text and generates the corresponding syntax tree,
 * 			with all its environment variables expanded.
 *
 * @param tree		Generated syntax tree
 * @param input		Input text received by the terminal
 * @param environ	Dictionary of enviroment variables
 * @param rcode		Return code of last command
 * @return t_error	Error code generated
 */
t_error	ast_parse(t_astree **tree, char *input, t_environ *environ, int rcode)
{
	t_tokens	*tokens;
	t_stlist	*stlist;
	t_error		error;

	*tree = NULL;
	error = tokenizer(&tokens, input);
	if (error)
		return (error);
	error = stl_analysis(&stlist, tokens);
	free_list(&tokens);
	if (error)
		return (error);
	error = ast_generate(tree, stlist);
	stl_free(&stlist);
	if (error)
		return (error);
	error = ast_expand(*tree, environ, rcode);
	if (error)
		ast_free(tree);
	return (error);
}
