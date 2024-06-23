/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:45:52 by mariza            #+#    #+#             */
/*   Updated: 2023/08/30 17:34:01 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *cmd, int character)
{
	const char	*last_found;

	last_found = NULL;
	while (*cmd != '\0')
	{
		if (*cmd == character)
			last_found = cmd;
		cmd++;
	}
	last_found++;
	return ((char *)last_found);
}
