/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusheo_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:34:17 by mariza            #+#    #+#             */
/*   Updated: 2022/12/11 17:52:05 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pila	*pusheo_one(char *argv[])
{
	char	**tab;
	int		size;
	t_pila	*pila_a;

	tab = ft_strsplit(argv[1], ' ');
	size = ft_tab_size(tab);
	if (!check_ok(tab))
		go_error(NULL, NULL);
	pila_a = pusheo(size, tab);
	return (pila_a);
}
