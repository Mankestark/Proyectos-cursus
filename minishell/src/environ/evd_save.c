/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:30:59 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/16 19:37:23 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

static int	evd_size(t_environ *environ);
static char	*envp_entry(t_environ *environ);

/**
 * @brief	Saves the minishell environment variables in string array format.
 * 			Each string contains the variable name and value separated by the
 * 			'=' character. If a memory allocation error occurs, the result will
 * 			be NULL.
 *
 * @param environ	Dictionary of minishell environment variables.
 * @param error		Error code generated.
 * @return char*	Environment variables with the same format as the system:
 * 					null-terminated array of strings.
 */
char	**evd_save(t_environ *environ, t_error *error)
{
	int		i;
	char	*entry;
	char	**result;

	*error = no_error;
	if (!environ)
		return (NULL);
	result = ft_calloc(evd_size(environ) + 1, sizeof(char *));
	if (!result)
		*error = mem_alloc_err;
	i = 0;
	while (environ)
	{
		entry = envp_entry(environ);
		if (!entry)
		{
			*error = mem_alloc_err;
			ft_free_array(&result);
			return (NULL);
		}
		result[i] = entry;
		environ = environ->next;
		i++;
	}
	return (result);
}

static int	evd_size(t_environ *environ)
{
	int	count;

	if (!environ)
		return (0);
	count = 0;
	while (environ)
	{
		environ = environ->next;
		count++;
	}
	return (count);
}

static char	*envp_entry(t_environ *environ)
{
	char	*result;
	int		name_len;
	int		value_len;

	if (!environ)
		return (NULL);
	name_len = ft_strlen(environ->name);
	value_len = ft_strlen(environ->value);
	result = ft_calloc(name_len + value_len + 2, sizeof(char));
	if (!result)
		return (NULL);
	ft_strncpy(result, environ->name, name_len);
	result[name_len] = '=';
	ft_strncpy(&result[name_len + 1], environ->value, value_len);
	result[name_len + value_len + 1] = '\0';
	return (result);
}
