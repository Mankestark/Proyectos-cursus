/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:56:56 by arimar            #+#    #+#             */
/*   Updated: 2022/12/09 00:46:23 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pila	*creart_pila(int numb)
{
	t_pila	*pila;

	pila = malloc(sizeof * pila);
	if (!pila)
		return (NULL);
	pila->numb = numb;
	pila->index = 0;
	pila->pos = -1;
	pila->target_pos = -1;
	pila->cost_a = -1;
	pila->cost_b = -1;
	pila->siguiente = NULL;
	return (pila);
}

void	push(int numb, t_pila **pila)
{
	t_pila	*t_pila;

	t_pila = creart_pila(numb);
	t_pila->siguiente = *pila;
	*pila = t_pila;
}

void	add_final(t_pila **pila, t_pila *new)
{
	t_pila	*cola;

	if (!new)
		return ;
	if (!*pila)
	{
		*pila = new;
		return ;
	}
	cola = ultimo_t_pila(*pila);
	cola->siguiente = new;
}

int	taman_pila(t_pila *pila)
{
	int	i;

	i = 0;
	if (!pila)
		return (0);
	while (pila)
	{
		pila = pila->siguiente;
		i++;
	}
	return (i);
}
