/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_delim_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:11:50 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/28 17:00:25 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static char				*init_values(t_quote_state *state, int *i, int len);
static t_quote_state	next_qstate(t_quote_state st, char c);

/**
 * @brief	Calculates the new text of the delimiter. The size of the new text
 * 			must be calculated and passed as an argument (`len`).
 *
 * @param text		Text of the node to be expanded from.
 * @param len		Length of new text after expansion.
 * @return char*	New text generated after expansion. NULL if there was an
 * 					error.
 */
char	*ast_delim_value(char *text, int len)
{
	t_quote_state	prev;
	t_quote_state	next;
	char			*result;
	int				i;

	result = init_values(&prev, &i, len);
	while (result && *text)
	{
		next = next_qstate(prev, *text);
		if (next == error_qstate)
		{
			ft_free((void **)&result);
			return (NULL);
		}
		if (prev & (def_qstate | sng_qstate | dbl_qstate) && prev == next)
			result[i++] = *text;
		prev = next;
		text++;
	}
	return (result);
}

static char	*init_values(t_quote_state *state, int *i, int len)
{
	char	*new_text;

	*state = def_qstate;
	*i = 0;
	new_text = ft_calloc(len + 1, sizeof(char));
	if (!new_text)
		return (NULL);
	new_text[len] = '\0';
	return (new_text);
}

static t_quote_state	next_qstate(t_quote_state st, char c)
{
	if ((st == def_qstate && c == '\'')
		|| (st == sng_qstate && c != '\''))
		return (sng_qstate);
	else if ((st == def_qstate && c == '"')
		|| (st == dbl_qstate && c != '"'))
		return (dbl_qstate);
	else if ((st == sng_qstate && c == '\'')
		|| (st == dbl_qstate && c == '"')
		|| (st == def_qstate))
		return (def_qstate);
	return (error_qstate);
}
