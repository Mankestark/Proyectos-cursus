/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:58:35 by mariza            #+#    #+#             */
/*   Updated: 2022/05/24 20:01:13 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
