/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:14:03 by mariza            #+#    #+#             */
/*   Updated: 2023/10/29 08:16:18 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*n;

	n = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!n)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		n[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		n[j++] = s2[i];
		i++;
	}
	n[j] = 0;
	return (n);
}
