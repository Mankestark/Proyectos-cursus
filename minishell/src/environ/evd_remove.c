/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:01:18 by jmorillo          #+#    #+#             */
/*   Updated: 2023/08/22 11:34:55 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

static void	remove_variable(t_environ *prev, t_environ *remove);

/**
 * @brief	Searches for the environment variable by name and removes it from
 * 			the dictionary, if present.
 *
 * @param env	Pointer to the dictionary of environment variables.
 * @param name	Name of the variable to be searched.
 */
void	evd_remove(t_environ **env, char *name)
{
	t_environ	*remove;

	if (!name || !(*name) || !(*env))
		return ;
	if (ft_str_cmp(name, (*env)->name) == 0)
	{
		remove = *env;
		*env = (*env)->next;
		remove->next = NULL;
		evd_free(&remove);
	}
	else
	{
		remove = *env;
		while (remove->next && ft_str_cmp(name, remove->next->name) > 0)
			remove = remove->next;
		if (remove->next && ft_str_cmp(name, remove->next->name) == 0)
			remove_variable(remove, remove->next);
	}
}

static void	remove_variable(t_environ *prev, t_environ *remove)
{
	prev->next = remove->next;
	remove->next = NULL;
	evd_free(&remove);
}
