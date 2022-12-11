/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:56:52 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/08 23:08:39 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_pila(t_pila **pila)
{
	t_pila	*tmp;

	if (!pila || !(*pila))
		return ;
	while (*pila)
	{
		tmp = (*pila)->siguiente;
		free(*pila);
		*pila = tmp;
	}
	*pila = NULL;
}

void	go_error(t_pila **pila_a, t_pila **pila_b)
{
	if (pila_a == NULL || *pila_a != NULL)
		free_pila(pila_a);
	if (pila_b == NULL || *pila_b != NULL)
		free_pila(pila_b);
	ft_printf("Error\n");
	exit(1);
}
