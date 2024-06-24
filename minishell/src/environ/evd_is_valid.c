/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:39:22 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/07 13:19:25 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

int	evd_is_valid(char *identifier)
{
	int	i;

	if (!identifier || !*identifier)
		return (0);
	i = 0;
	while (identifier[i])
	{
		if (!ft_is_alpha(identifier[i]))
		{
			if (i == 0)
				return (0);
			else if (!ft_is_alphanum(identifier[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
