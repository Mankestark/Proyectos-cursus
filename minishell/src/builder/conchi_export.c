/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conchi_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:36:09 by mariza            #+#    #+#             */
/*   Updated: 2023/11/04 13:59:59 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

static void	split_export(char *input, char **variable, char **value);
static int	has_equal(char *text);

int	conchi_export(t_arg_node *args, t_environ **env)
{
	char	*variable;
	char	*value;

	variable = NULL;
	value = NULL;
	while (args)
	{
		if (!has_equal(args->text) && !evd_is_valid(args->text))
			print_errors(identifier_err, NULL, 1);
		else if (has_equal(args->text))
		{
			split_export(args->text, &variable, &value);
			if (variable == NULL || value == NULL || !evd_is_valid(variable))
			{
				print_errors(identifier_err, NULL, 1);
				ft_free((void **)&variable);
				ft_free((void **)&value);
			}
			else if (evd_set(env, variable, value) != no_error)
				return (1);
		}
		args = args->next;
	}
	return (0);
}

static int	has_equal(char *text)
{
	return (ft_strchr(text, '=') != NULL);
}

static void	split_export(char *input, char **variable, char **value)
{
	const char	*equals;
	size_t		length;

	equals = ft_strchr(input, '=');
	length = equals - input;
	*variable = (char *)ft_calloc(length + 1, 1);
	if (!*variable)
		return ;
	ft_strncpy(*variable, input, length);
	*value = ft_strdup(&input[length + 1]);
	if (*value == NULL)
		ft_free((void **)variable);
}
