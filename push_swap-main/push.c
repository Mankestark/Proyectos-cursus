/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 00:29:50 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/11 17:26:08 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pila	*pusheo(int argc, char *argv[])
{
	t_pila		*pila_a;
	long int	nb;

	nb = 0;
	pila_a = NULL;
	while (argc > 1)
	{
		nb = ft_atoi(argv[argc - 1]);
		if (nb > 2147483547 || nb < -2147483648)
			go_error(&pila_a, NULL);
		if (argc == 1)
			pila_a = creart_pila((int)nb);
		else
			push(nb, &pila_a);
		argc--;
	}
	return (pila_a);
}

void	init_index(t_pila *pila_a, int pila_lenght)
{
	t_pila	*ptr;
	t_pila	*high;
	int		val;

	while (--pila_lenght > 0)
	{
		ptr = pila_a;
		val = INT_MIN;
		high = NULL;
		while (ptr)
		{
			if (ptr->numb == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->numb > val && ptr->index == 0)
			{
				val = ptr->numb;
				high = ptr;
				ptr = pila_a;
			}
			else
				ptr = ptr->siguiente;
		}
		if (high != NULL)
			high->index = pila_lenght;
	}
}
