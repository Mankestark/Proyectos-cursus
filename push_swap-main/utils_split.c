/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:27:18 by mariza            #+#    #+#             */
/*   Updated: 2022/12/11 17:31:02 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	mem = (void *)malloc(sizeof(char) * (size + 1));
	if (!(mem))
		return (NULL);
	mem[size] = '\0';
	ft_bzero(mem, size);
	return (mem);
}
