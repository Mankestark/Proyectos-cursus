/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:54:14 by jmorillo          #+#    #+#             */
/*   Updated: 2023/09/03 12:28:56 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_abs(int n);

char	*ft_itoa(int n)
{
	char	*result;
	size_t	pos;
	size_t	digits;

	digits = ft_num_len(n);
	result = malloc(digits + 1);
	result[digits] = '\0';
	if (!result)
		return (result);
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	pos = digits - 1;
	while (n)
	{
		result[pos] = ft_abs(n % 10) + 48;
		n = n / 10;
		pos--;
	}
	return (result);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
