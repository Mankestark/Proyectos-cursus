/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:54:27 by jmorillo          #+#    #+#             */
/*   Updated: 2023/07/29 13:03:16 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
	Compara dos cadenas de texto.
	Argumentos:
	- s1:	Primera cadena de texto a comparar.
	- s2:	Segunda cadena de texto a comparar.
	Retorna:
		0		Si las dos cadenas son iguales o nulas.
		>0		Si la cadena primera es mayor.
		<0		Si la cadena primera es menor.
		256		Si la cadena segunda es nula.
		-256	Si la cadena primera es nula.
*/
int	ft_str_cmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 && s2)
		return (-256);
	if (s1 && !s2)
		return (256);
	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
