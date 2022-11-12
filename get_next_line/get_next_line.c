/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:56:30 by mac-pap           #+#    #+#             */
/*   Updated: 2022/09/26 18:56:59 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*func_read(int fd, char *count)
{
	char	*buff;
	int		mini_buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	mini_buff = 1;
	while (!ft_strchr(count, '\n') && mini_buff != 0)
	{
		mini_buff = read(fd, buff, BUFFER_SIZE);
		if (mini_buff == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[mini_buff] = '\0';
		count = ft_strjoin(count, buff);
	}
	free(buff);
	return (count);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	count = func_read(fd, count);
	if (!count)
		return (NULL);
	line = new_line(count);
	count = new_count(count);
	return (line);
}
