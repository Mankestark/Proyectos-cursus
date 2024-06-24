/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:16:25 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/16 19:31:47 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

/**
 * @brief	Frees the environment variable dictionary from memory.
 *
 * @param env	Pointer to the dictionary of environment variables.
 */
void	evd_free(t_environ **env)
{
	if (!env || !(*env))
		return ;
	evd_free(&(*env)->next);
	ft_free((void **)&(*env)->name);
	ft_free((void **)&(*env)->value);
	ft_free((void **)env);
}
