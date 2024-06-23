/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:25:15 by mariza            #+#    #+#             */
/*   Updated: 2023/10/14 21:24:07 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

t_error	add_token(t_tokens **list, char *word)
{
	t_tokens	*new_token;
	t_tokens	*current_token;
	t_error		error;

	error = no_error;
	new_token = ft_calloc(1, sizeof(t_tokens));
	if (!new_token)
		return (mem_alloc_err);
	new_token->token = ft_strdup(word);
	if (!new_token->token)
	{
		ft_free((void **)&new_token);
		return (mem_alloc_err);
	}
	new_token->next = NULL;
	if (*list == NULL)
		*list = new_token;
	else
	{
		current_token = *list;
		while (current_token->next != NULL)
			current_token = current_token->next;
		current_token->next = new_token;
	}
	return (error);
}
