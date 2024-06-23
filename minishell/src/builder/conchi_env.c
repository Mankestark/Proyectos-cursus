/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conchi_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 23:40:33 by mariza            #+#    #+#             */
/*   Updated: 2023/08/22 18:23:18 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

int	conchi_env(t_environ *env)
{
	t_environ	*list;

	list = env;
	if (list == NULL)
		return (1);
	while (list)
	{
		printf("%s = %s\n", list->name, list->value);
		list = list->next;
	}
	return (0);
}
