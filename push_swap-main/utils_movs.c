/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:04:36 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/08 21:32:15 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_rev_rotate_both(t_pila **pila_a, t_pila **pila_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(pila_a, pila_b);
	}
}

static void	do_rotate_both(t_pila **pila_a, t_pila **pila_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(pila_a, pila_b);
	}
}

static void	do_rotate_a(t_pila **pila_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(pila_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(pila_a);
			(*cost)++;
		}
	}
}

static void	do_rotate_b(t_pila **pila_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(pila_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(pila_b);
			(*cost)++;
		}
	}
}

void	do_move(t_pila **pila_a, t_pila **pila_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(pila_a, pila_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(pila_a, pila_b, &cost_a, &cost_b);
	do_rotate_a(pila_a, &cost_a);
	do_rotate_b(pila_b, &cost_b);
	pa(pila_a, pila_b);
}
