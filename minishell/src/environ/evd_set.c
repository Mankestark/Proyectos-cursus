/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:01:18 by jmorillo          #+#    #+#             */
/*   Updated: 2023/11/03 12:04:35 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

static t_environ	*create_variable(char *name, char *value);
static void			replace_value(t_environ *node, t_environ *new_node);
static void			insert_variable(t_environ *environ, t_environ *variable);
static void			insert_first_vble(t_environ **environ, t_environ *variable);

/**
 * @brief	Creates the environment variable from name and value, and adds it
 * 			to the dictionary. If the variable already exists, then replace its
 * 			value. If the name is null, an invalid identifier error is
 * 			generated.
 * 			The arguments name and value are stored directly, not copied.
 *
 * @param env		Pointer to the dictionary of environment variables.
 * @param name		Name of the variable to be created.
 * @param value		Value of the variable to be assigned.
 * @return t_error	Error code generated.
 */
t_error	evd_set(t_environ **env, char *name, char *value)
{
	t_environ	*variable;

	if (!name || !(*name))
	{
		ft_free((void **)&name);
		ft_free((void **)&value);
		return (identifier_err);
	}
	variable = create_variable(name, value);
	if (!variable)
	{
		ft_free((void **)&name);
		ft_free((void **)&value);
		return (mem_alloc_err);
	}
	if (!(*env) || ft_str_cmp(name, (*env)->name) <= 0)
		insert_first_vble(env, variable);
	else
		insert_variable(*env, variable);
	return (no_error);
}

static t_environ	*create_variable(char *name, char *value)
{
	t_environ	*new_vble;

	new_vble = ft_calloc(1, sizeof(t_environ));
	if (!new_vble)
		return (NULL);
	new_vble->name = name;
	new_vble->value = value;
	new_vble->next = NULL;
	return (new_vble);
}

static void	insert_first_vble(t_environ **environ, t_environ *variable)
{
	if ((*environ) && ft_str_cmp(variable->name, (*environ)->name) == 0)
		replace_value(*environ, variable);
	else
	{
		variable->next = *environ;
		*environ = variable;
	}
}

static void	insert_variable(t_environ *environ, t_environ *variable)
{
	while (environ->next
		&& ft_str_cmp(variable->name, environ->next->name) > 0)
		environ = environ->next;
	if (environ->next && ft_str_cmp(variable->name, environ->next->name) == 0)
		replace_value(environ->next, variable);
	else
	{
		variable->next = environ->next;
		environ->next = variable;
	}
}

static void	replace_value(t_environ *node, t_environ *new_node)
{
	ft_free((void **)&node->value);
	node->value = new_node->value;
	ft_free((void **)&new_node->name);
	ft_free((void **)&new_node);
}
