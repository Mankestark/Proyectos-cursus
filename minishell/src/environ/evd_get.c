/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:01:30 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/22 11:19:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

/**
 * @brief	Search for the environment variable by its name in the list. Returns
 * 			its value if it is contained in the list.
 *
 * @param env		Pointer to the dictionary of environment variables.
 * @param name		Name of the variable to be searched.
 * @return char*	Value of the variable if it is in the list. NULL otherwise.
 */
char	*evd_get(t_environ *env, char *name)
{
	char	*value;

	if (!env || !name)
		return (NULL);
	value = NULL;
	while (env && ft_str_cmp(name, env->name) > 0)
		env = env->next;
	if (env && ft_str_cmp(name, env->name) == 0)
		value = env->value;
	return (value);
}
