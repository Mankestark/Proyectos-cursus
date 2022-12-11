/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:55:57 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/08 22:14:17 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	obt_posicion(t_pila **pila)
{
	t_pila	*tmp;
	int		i;

	tmp = *pila;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->siguiente;
		i++;
	}
}

int	index_minor(t_pila **pila)
{
	t_pila	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *pila;
	lowest_index = INT_MAX;
	obt_posicion(pila);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->siguiente;
	}
	return (lowest_pos);
}

static int	objetivo(t_pila **pila_a, int b_idx, int target_idx, int target_pos)
{
	t_pila	*tmp_a;

	tmp_a = *pila_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->siguiente;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *pila_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->siguiente;
	}
	return (target_pos);
}

void	posicion_objetivo(t_pila **pila_a, t_pila **pila_b)
{
	t_pila	*tmp_b;
	int		target_pos;

	tmp_b = *pila_b;
	obt_posicion(pila_a);
	obt_posicion(pila_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = objetivo(pila_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->siguiente;
	}
}
