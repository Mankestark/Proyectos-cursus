/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:02:34 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/08 22:16:06 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_cost(t_pila **pila_a, t_pila **pila_b)
{
	t_pila	*tmp_a;
	t_pila	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *pila_a;
	tmp_b = *pila_b;
	size_a = taman_pila(tmp_a);
	size_b = taman_pila(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->siguiente;
	}
}

void	do_cheapest_move(t_pila **pila_a, t_pila **pila_b)
{
	t_pila	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *pila_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->siguiente;
	}
	do_move(pila_a, pila_b, cost_a, cost_b);
}
