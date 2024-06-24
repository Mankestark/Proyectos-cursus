/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:36:10 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 19:11:15 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/stl.h"

/**
 * @brief	Frees the list and assigns NULL to the pointer. This avoids double
 * 			releases. If the pointer to the list is NULL, nothing is done.
 *
 * @param stlist	Memory address of the pointer to the list.
 */
void	stl_free(t_stlist **list)
{
	if (!list || !(*list))
		return ;
	stl_free(&(*list)->next);
	free((*list)->token);
	ft_free((void **)list);
}
