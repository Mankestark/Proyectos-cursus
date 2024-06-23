/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_special_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:52:02 by mariza            #+#    #+#             */
/*   Updated: 2023/10/14 09:43:14 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

t_error	handle_special_char(t_tokens **list, char *command_line, int *init_word)
{
	int		final_word;
	t_error	error;

	error = no_error;
	final_word = *init_word;
	final_word++;
	if (command_line[*init_word] != '|'
		&& command_line[*init_word] == command_line[final_word])
		final_word++;
	error = split_tokens(list, command_line, final_word, *init_word);
	*init_word = final_word;
	return (error);
}
