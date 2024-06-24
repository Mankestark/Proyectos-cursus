/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:27:02 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 19:11:34 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl_toolkit.h"

static t_error	free_on_error(t_stlist **list, char *token, t_error err_value);

/**
 * @brief	Parses the list of tokens and generates a new list of tokens with
 * 			their type.
 *
 * @param t_stlist*		A list of tokens with their type. The contents of the
 * 						tokens are duplicated to avoid failures when the list
 * 						passed as argument is freed. If the token list is
 * 						empty, NULL is returned.
 * @param tokens		List of tokens generated from the command line. This
 * 						list is parsed but not freed from memory.
 * @return error			Error code generated during function execution.
 */
t_error	stl_analysis(t_stlist **list, t_tokens *tokens)
{
	char		*token;
	t_tkn_type	type;
	t_error		error;

	*list = NULL;
	while (tokens)
	{
		token = ft_strdup(tokens->token);
		if (!token)
			return (free_on_error(list, token, mem_alloc_err));
		type = stl_guess_type(*list, tokens->token);
		if (type == unknown_tkn)
			return (free_on_error(list, token, syntax_err));
		error = stl_add(list, token, type);
		if (error)
			return (free_on_error(list, token, error));
		if (!tokens->next && (type == pipe_tkn || type == write_tkn
				|| type == read_tkn || type == append_tkn
				|| type == delimiter_tkn))
			return (free_on_error(list, NULL, syntax_err));
		tokens = tokens->next;
	}
	return (no_error);
}

static t_error	free_on_error(t_stlist **list, char *token, t_error err_value)
{
	stl_free(list);
	ft_free((void **)&token);
	return (err_value);
}
