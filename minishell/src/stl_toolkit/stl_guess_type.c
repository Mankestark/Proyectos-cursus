/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_guess_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:46:40 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/09 19:26:32 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl_toolkit.h"

static t_tkn_type	guess_symbol(char *token);
static void			update_state(t_tkn_state *state, int *command,
						t_stlist *node);
static t_tkn_type	text_type_from_state(t_tkn_state state, int command);

/**
 * @brief	Find out the token type based on the token content and the partial
 * 			list of semantic tokens.
 *
 * @param list			List of semantic tokens analyzed so far.
 * @param token			Token to be parsed.
 * @return t_tkn_type	A token type corresponding to the token to be parsed.
 * 						These values are defined in the stl header.
 * 						'unknown_tkn' in case of syntactic error.
 *
 */
t_tkn_type	stl_guess_type(t_stlist *list, char *token)
{
	t_tkn_type	type;
	t_tkn_state	state;
	int			has_command;

	state = default_state;
	has_command = 0;
	while (list)
	{
		update_state(&state, &has_command, list);
		list = list->next;
	}
	type = guess_symbol(token);
	if (type && state == error_state)
		type = unknown_tkn;
	else if (!type)
		type = text_type_from_state(state, has_command);
	return (type);
}

/**
 * @brief	Find out the type of operator based on the token content.
 *
 * @param token	Text string to parse.
 * @return int	An integer if it is an operator, being greater than 0, which
 * 				corresponds to the type of the token. '0' Otherwise (not an
 * 				operator).
 */
static t_tkn_type	guess_symbol(char *token)
{
	if (ft_str_cmp(token, "|") == 0)
		return (pipe_tkn);
	else if (ft_str_cmp(token, ">") == 0)
		return (write_tkn);
	else if (ft_str_cmp(token, ">>") == 0)
		return (append_tkn);
	else if (ft_str_cmp(token, "<") == 0)
		return (read_tkn);
	else if (ft_str_cmp(token, "<<") == 0)
		return (delimiter_tkn);
	return (unknown_tkn);
}

/**
 * @brief	Updates the list state and command state according to the
 * 			current state and node.
 *
 * @param state		Current state of the list.
 * @param command	If the command is present in the analyzed fraction.
 * @param node		Current node of the list.
 */
static void	update_state(t_tkn_state *state, int *command, t_stlist *node)
{
	if (*state == redir_state && stl_is_text(node))
		*state = stream_state;
	else if (*state != redir_state && stl_is_redir(node))
		*state = redir_state;
	else if ((*state == default_state
			|| (*state == stream_state && *command == 0)) && stl_is_text(node))
	{
		*state = command_state;
		*command = 1;
	}
	else if ((*state & (command_state | argument_state | stream_state))
		&& *command == 1 && stl_is_text(node))
		*state = argument_state;
	else if (*state & ~(redir_state | default_state) && stl_is_pipe(node))
	{
		*state = default_state;
		*command = 0;
	}
	else
		*state = error_state;
}

static t_tkn_type	text_type_from_state(t_tkn_state state, int command)
{
	if (state == default_state)
		return (command_tkn);
	else if (state == command_state)
		return (argument_tkn);
	else if (state == argument_state)
		return (argument_tkn);
	else if (state == redir_state)
		return (stream_tkn);
	else if (state == stream_state && command)
		return (argument_tkn);
	else if (state == stream_state)
		return (command_tkn);
	else
		return (unknown_tkn);
}
