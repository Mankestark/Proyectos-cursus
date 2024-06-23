/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_delim_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:41:33 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/28 17:00:43 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static t_quote_state	next_qstate(t_quote_state st, char c);

/**
 * @brief	Calculates the length of the delimiter.
 *
 * @param text	Text of the node to calculate length
 * @return int	The length of the new text. `-1` if an error occurred.
 */
int	ast_delim_len(char *text)
{
	int				count;
	t_quote_state	state;
	t_quote_state	new_state;

	count = 0;
	state = def_qstate;
	while (*text)
	{
		new_state = next_qstate(state, *text);
		if (new_state == error_qstate)
			return (-1);
		if (state & (def_qstate | sng_qstate | dbl_qstate)
			&& state == new_state)
			count++;
		state = new_state;
		text++;
	}
	return (count);
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
