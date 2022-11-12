/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 01:14:00 by mac-pap           #+#    #+#             */
/*   Updated: 2022/09/26 19:08:44 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *count, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!count)
	{
		count = (char *)malloc(1 * sizeof(char));
		count[0] = '\0';
	}
	if (!count || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(count) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (count)
		while (count[++i] != '\0')
			str[i] = count[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(count) + ft_strlen(buff)] = '\0';
	free(count);
	return (str);
}

char	*new_line(char *count)
{
	int		i;
	char	*str;

	i = 0;
	if (!count[i])
		return (NULL);
	while (count[i] && count[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (count[i] && count[i] != '\n')
	{
		str[i] = count[i];
		i++;
	}
	if (count[i] == '\n')
	{
		str[i] = count[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_count(char *count)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (count[i] && count[i] != '\n')
		i++;
	if (!count[i])
	{
		free(count);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(count) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (count[i])
		str[j++] = count[i++];
	str[j] = '\0';
	free(count);
	return (str);
}
