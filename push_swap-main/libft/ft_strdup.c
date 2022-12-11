/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:12:30 by mariza            #+#    #+#             */
/*   Updated: 2022/05/24 20:01:19 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*n;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	n = (char *)malloc(sizeof(*n) * (j + 1));
	if (!n)
		return (NULL);
	while (i < j)
	{
		n[i] = s1[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
