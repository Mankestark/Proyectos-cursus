/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:49:25 by mariza            #+#    #+#             */
/*   Updated: 2023/10/14 20:17:19 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

t_error	split_tokens(t_tokens **list, char *comand_line, int final_word,
		int init_word)
{
	int		length_word;
	char	*word;
	t_error	error;

	error = no_error;
	word = NULL;
	length_word = (final_word - init_word);
	if (length_word > 0)
	{
		word = ft_calloc(length_word + 1, sizeof(char));
		if (!word)
			return (mem_alloc_err);
		ft_strncpy(word, comand_line + init_word, length_word);
		word[length_word] = '\0';
		error = add_token(list, word);
		ft_free((void **)&word);
	}
	return (error);
}
