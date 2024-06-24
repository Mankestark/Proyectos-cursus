/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:25:15 by mariza            #+#    #+#             */
/*   Updated: 2023/10/16 10:48:18 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

static t_error	check_quotes(char *command);

t_error	tokenizer(t_tokens **list, char *command_line)
{
	int		pos;
	int		length;
	t_error	error;

	*list = NULL;
	error = check_quotes(command_line);
	length = ft_strlen(command_line);
	pos = 0;
	while (pos < length && error == no_error)
	{
		while (pos < length && ft_isspace(command_line[pos]))
			pos++;
		if (is_special_char(command_line[pos]))
			error = handle_special_char(list, command_line, &pos);
		else
			error = handle_normal_token(list, command_line, length, &pos);
	}
	return (error);
}

static t_error	check_quotes(char *command)
{
	int	quotesingle;
	int	quotedouble;
	int	i;

	quotesingle = 0;
	quotedouble = 0;
	i = 0;
	while (command[i] != '\0')
	{
		if (command[i] == '\'' && !quotedouble)
			quotesingle = !quotesingle;
		else if (command[i] == '\"' && !quotesingle)
			quotedouble = !quotedouble;
		i++;
	}
	if (quotesingle || quotedouble)
		return (quote_err);
	return (no_error);
}
