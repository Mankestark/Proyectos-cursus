/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:16:50 by papa42            #+#    #+#             */
/*   Updated: 2022/05/17 18:45:23 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t				i;
	unsigned const char	*s2;
	unsigned char		*s1;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1 == s2 || !n)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
