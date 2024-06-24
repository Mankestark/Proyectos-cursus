/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:25:14 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/31 10:29:50 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief	Counts the number of characters of an integer. In case of a negative
 * 			number, the minus sign is also included.
 *
 * @param n		Integer to calculate its size.
 * @return int	Returns the character size of the number.
 */
int	ft_num_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	else if (n == 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
