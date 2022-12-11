/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:03:51 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/04 00:28:37 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_pila(t_pila **pila)
{
	t_pila	*temp;
	t_pila	*temp2;

	temp = *pila;
	*pila = (*pila)->siguiente;
	temp2 = ultimo_t_pila(*pila);
	temp->siguiente = NULL;
	temp2->siguiente = temp;
}

void	ra(t_pila **pila_a)
{
	rotate_pila(pila_a);
	ft_printf("ra\n");
}

void	rb(t_pila **pila_b)
{
	rotate_pila(pila_b);
	ft_printf("rb\n");
}

void	rr(t_pila **pila_a, t_pila **pila_b)
{
	rotate_pila(pila_a);
	rotate_pila(pila_b);
	ft_printf("rr\n");
}
