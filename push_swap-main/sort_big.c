/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:29:16 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/08 22:11:42 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_menos_tres(t_pila **pila_a, t_pila **pila_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = taman_pila(*pila_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*pila_a)->index <= stack_size / 2)
		{
			pb(pila_a, pila_b);
			pushed++;
		}
		else
			ra(pila_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(pila_a, pila_b);
		pushed++;
	}
}

static void	change_stack(t_pila **pila_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = taman_pila(*pila_a);
	lowest_pos = index_minor(pila_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(pila_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(pila_a);
			lowest_pos--;
		}
	}
}

void	sort(t_pila **pila_a, t_pila **pila_b)
{
	push_menos_tres(pila_a, pila_b);
	sort_peque(pila_a);
	while (*pila_b)
	{
		posicion_objetivo(pila_a, pila_b);
		get_cost(pila_a, pila_b);
		do_cheapest_move(pila_a, pila_b);
	}
	if (!check_sorted(*pila_a))
		change_stack(pila_a);
}
