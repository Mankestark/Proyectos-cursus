/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:54:04 by mariza            #+#    #+#             */
/*   Updated: 2023/09/03 12:29:12 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (((char *)s)[i] != '\0' && flag == 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
			flag = 1;
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	if (!c)
		return ((char *) &s[i]);
	return (NULL);
}
