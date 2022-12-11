/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:11:53 by papa              #+#    #+#             */
/*   Updated: 2022/12/04 00:27:09 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_sign(char c)
{
	return (c == '+' || c == '-');
}

int	check_arg_comp(const char *c1, const char *c2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (c1[i] == '+')
	{
		if (c2[j])
			i++;
	}
	else
	{
		if (c2[j] == '+')
			j++;
	}
	while (c1[i] && c2[j] && c1[i] == c2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)c1[i] - (unsigned char)c2[j]);
}
