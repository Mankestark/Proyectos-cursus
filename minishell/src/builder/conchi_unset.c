/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conchi_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:56:28 by mariza            #+#    #+#             */
/*   Updated: 2023/11/04 13:00:54 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	conchi_unset(t_arg_node *args, t_environ **env)
{
	char	*variable;

	while (args)
	{
		variable = args->text;
		if (evd_is_valid(variable))
			evd_remove(env, variable);
		else
			print_errors(identifier_err, NULL, 1);
		args = args->next;
	}
	return (0);
}
