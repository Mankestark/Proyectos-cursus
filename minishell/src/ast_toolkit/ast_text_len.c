/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_text_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:41:33 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/28 16:14:54 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static char				*get_vble_name(char *text, int end);
static t_quote_state	next_qstate(t_quote_state st, char c);
static int				count_vble_len(char **text, t_environ *environ,
							int return_code);

/**
 * @brief	Calculates the length of the node text after expansion of the
 * 			variables, if present.
 *
 * @param text			Text of the node to calculate length
 * @param environ		Terminal environment variables.
 * @param return_code	Return code of the last command executed.
 * @return int			The length of the new text. `-1` if an error occurred.
 */
int	ast_text_len(char *text, t_environ *environ, int return_code)
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
		if (new_state == variable_qstate)
		{
			count += count_vble_len(&text, environ, return_code);
			new_state = state;
		}
		else if (state & (def_qstate | sng_qstate | dbl_qstate)
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
	else if (st & (def_qstate | dbl_qstate) && c == '$')
		return (variable_qstate);
	else if ((st == def_qstate && c == '"')
		|| (st == dbl_qstate && c != '$' && c != '"'))
		return (dbl_qstate);
	else if ((st == sng_qstate && c == '\'')
		|| (st == dbl_qstate && c == '"')
		|| (st == def_qstate && c != '$'))
		return (def_qstate);
	return (error_qstate);
}

static char	*get_vble_name(char *text, int end)
{
	char	*result;

	result = ft_calloc(end + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_strncpy(result, text, end);
	result[end] = '\0';
	return (result);
}

static int	count_vble_len(char **text, t_environ *environ, int return_code)
{
	int		name_end;
	int		vble_size;
	char	*name;

	(*text)++;
	if (!ft_is_alpha(**text) && **text != '?')
	{
		(*text)--;
		return (1);
	}
	else if (**text == '?')
		return (ft_num_len(return_code));
	name_end = 0;
	while ((*text)[name_end] && ft_is_alphanum((*text)[name_end]))
		name_end++;
	name = get_vble_name((*text), name_end);
	if (name && evd_get(environ, name))
		vble_size = ft_strlen(evd_get(environ, name));
	else
		vble_size = 0;
	ft_free((void **)&name);
	(*text) += name_end - 1;
	return (vble_size);
}
