/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:59:02 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/16 10:51:33 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_free_array(char ***pointer_to_array)
{
	char	**char_array;
	int		i;

	char_array = *pointer_to_array;
	i = 0;
	if (char_array == NULL)
		return ;
	while (char_array[i])
	{
		free(char_array[i]);
		char_array[i] = NULL;
		i++;
	}
	free(*pointer_to_array);
	*pointer_to_array = NULL;
}
