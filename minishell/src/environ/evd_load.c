/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evd_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:30:59 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/16 19:29:53 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environ.h"

static t_error	parse_variable(char *line, char **name, char **value);

/**
 * @brief	Reads the system environment variables. Parses and separates
 * 			variable names and values. The result is stored in a dictionary.
 * 			If an identifier or memory reservation error occurs, the dictionary
 * 			will be null.
 *
 * @param envp			System environment variables.
 * @param error			Error code generated.
 * @return t_environ*	Pointer to the generated dictionary.
 */
t_environ	*evd_load(char **envp, t_error *error)
{
	int			i;
	t_environ	*environ;
	char		*name;
	char		*value;

	i = 0;
	environ = NULL;
	while (envp[i])
	{
		*error = parse_variable(envp[i], &name, &value);
		if (*error)
		{
			evd_free(&environ);
			return (NULL);
		}
		*error = evd_set(&environ, name, value);
		if (*error)
		{
			evd_free(&environ);
			return (NULL);
		}
		i++;
	}
	return (environ);
}

static t_error	parse_variable(char *line, char **name, char **value)
{
	int	equal_pos;

	equal_pos = 0;
	while (line[equal_pos] != '=')
		equal_pos++;
	*value = ft_strdup(&line[equal_pos + 1]);
	if (!(*value) && ft_strlen(&line[equal_pos + 1]))
		return (mem_alloc_err);
	*name = ft_calloc(equal_pos + 1, sizeof(char));
	if (!(*name))
		return (mem_alloc_err);
	(*name)[equal_pos] = '\0';
	*name = ft_strncpy(*name, line, equal_pos);
	return (no_error);
}
