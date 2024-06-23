/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_text_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:11:50 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/28 16:09:29 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast_toolkit.h"

static char				*init_values(t_quote_state *state, int *i, int len);
static t_quote_state	next_qstate(t_quote_state st, char c);
static int				write_vble_value(char *value, char **text,
							t_environ *environ, int return_code);
static int				copy_variable(char *text, char *new_text, int end,
							t_environ *environ);

/**
 * @brief	Calculates the new text of the node after expanding the environment
 * 			variables it contained. The size of the new text must be calculated
 * 			and passed as an argument (`len`).
 *
 * @param text		Text of the node to be expanded from.
 * @param len		Length of new text after expansion.
 * @param environ	Terminal environment variables.
 * @param rcode		Return code of the last command executed in the terminal.
 * @return char*	New text generated after expansion. NULL if there was an
 * 					error.
 */
char	*ast_text_value(char *text, int len, t_environ *environ, int rcode)
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
		if (next == variable_qstate)
		{
			i += write_vble_value(&result[i], &text, environ, rcode);
			next = prev;
		}
		else if (prev & (def_qstate | sng_qstate | dbl_qstate) && prev == next)
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

static int	write_vble_value(char *value, char **text, t_environ *environ,
	int return_code)
{
	int		name_end;
	int		vble_size;
	char	*name;

	(*text)++;
	if (!ft_is_alpha(**text) && **text != '?')
	{
		*value = '$';
		(*text)--;
		return (1);
	}
	else if (**text == '?')
	{
		name = ft_itoa(return_code);
		ft_strncpy(value, name, ft_strlen(name));
		ft_free((void **)&name);
		return (ft_num_len(return_code));
	}
	name_end = 0;
	while ((*text)[name_end] && ft_is_alphanum((*text)[name_end]))
		name_end++;
	vble_size = copy_variable((*text), value, name_end, environ);
	(*text) += name_end - 1;
	return (vble_size);
}

static int	copy_variable(char *text, char *new_text, int end,
	t_environ *environ)
{
	int		vble_len;
	char	*vble_name;
	char	*vble_value;

	if (!end)
		return (0);
	vble_name = ft_calloc(end + 1, sizeof(char));
	if (!vble_name)
		return (0);
	ft_strncpy(vble_name, text, end);
	vble_name[end] = '\0';
	vble_value = evd_get(environ, vble_name);
	if (vble_name && vble_value)
	{
		vble_len = ft_strlen(vble_value);
		ft_strncpy(new_text, vble_value, vble_len);
	}
	else
		vble_len = 0;
	ft_free((void **)&vble_name);
	return (vble_len);
}
