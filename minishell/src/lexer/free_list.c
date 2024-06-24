/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:25:15 by mariza            #+#    #+#             */
/*   Updated: 2023/10/14 21:25:31 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

void	free_list(t_tokens **list)
{
	t_tokens	*delete_token;

	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		delete_token = *list;
		*list = (*list)->next;
		ft_free((void **)&delete_token->token);
		ft_free((void **)&delete_token);
	}
	*list = NULL;
}
