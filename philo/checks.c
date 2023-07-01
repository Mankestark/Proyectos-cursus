/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:46:56 by mankestark        #+#    #+#             */
/*   Updated: 2023/06/28 13:29:27 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

//chequeo para combrobar que solo se introducen digitos
static bool	contains_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

//atoi con limite de entero
int	int_atoi(char *str)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

//validacion principal de argumentos
bool	valid_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!contains_only_digits(av[i]))
			return (errormsg(ERROR_DIGIT, av[i], false));
		nb = int_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (errormsg(ERROR_ARGS, ERROR_MAXMINPHIL, false));
		if (i != 1 && nb == -1)
			return (errormsg(ERROR_DIGIT, av[i], false));
		i++;
	}
	return (true);
}
