/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 06:09:54 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/04 00:29:04 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_pila *pila)
{
	int	temp;

	if (pila == NULL || pila->siguiente == NULL)
		return ;
	temp = pila->numb;
	pila->numb = pila->siguiente->numb;
	pila->siguiente->numb = temp;
	temp = pila->index;
	pila->index = pila->siguiente->index;
	pila->siguiente->index = temp;
}

void	sa(t_pila **pila_a)
{
	swap(*pila_a);
	ft_printf("sa\n");
}

void	sb(t_pila **pila_b)
{
	swap(*pila_b);
	ft_printf("sb\n");
}

void	ss(t_pila **pila_a, t_pila **pila_b)
{
	swap(*pila_a);
	swap(*pila_b);
	ft_printf("ss\n");
}
