/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_normal_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:52:02 by mariza            #+#    #+#             */
/*   Updated: 2023/10/16 10:47:59 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

static void	handle_quotes(char *command_line, int *pos);

t_error	handle_normal_token(t_tokens **list, char *command_line, int length,
		int *init_word)
{
	int		final_word;
	t_error	error;

	error = no_error;
	final_word = *init_word;
	while (final_word < length && !ft_isspace(command_line[final_word])
		&& !is_special_char(command_line[final_word]))
	{
		if (command_line[final_word] == '\''
			|| command_line[final_word] == '"')
			handle_quotes(command_line, &final_word);
		else
			final_word++;
	}
	error = split_tokens(list, command_line, final_word, *init_word);
	*init_word = final_word;
	return (error);
}

static void	handle_quotes(char *command_line, int *pos)
{
	char	quote;

	quote = command_line[*pos];
	*pos += 1;
	while (command_line[*pos] != quote)
		*pos += 1;
	*pos += 1;
}
