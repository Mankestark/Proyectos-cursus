/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:58:54 by mankestarkd       #+#    #+#             */
/*   Updated: 2022/12/09 00:47:02 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pila	*ultimo_t_pila(t_pila *pila)
{
	while (pila && pila->siguiente != NULL)
		pila = pila->siguiente;
	return (pila);
}

t_pila	*penultimo_t_pila(t_pila *pila)
{
	while (pila && pila->siguiente && pila->siguiente->siguiente != NULL)
		pila = pila->siguiente;
	return (pila);
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	imprimirpila(t_pila **pila)
{
	t_pila	*temp;

	temp = *pila;
	while (temp)
	{
		ft_printf("%d\n", temp->numb);
		temp = temp->siguiente;
	}
}
