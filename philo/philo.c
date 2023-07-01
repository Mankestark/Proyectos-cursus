/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papa <papa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:47:15 by mankestark        #+#    #+#             */
/*   Updated: 2023/06/30 11:17:10 by papa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"
//empieza la simulacion una vez inicializadas las estructuras
//, asignados los mutex y los tenedores
//tambien inicia la funcion philosopher para iniciar el hilo
static bool	start(t_lunch *data)
{
	unsigned int	i;

	data->start_time = get_time_in_ms() + (data->nb_philos * 2 * 10);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i]->thread, NULL, &philosopher,
				data->philos[i]) != 0)
			return (error_mem(ERROR_THREAD, NULL, data));
		i++;
	}
	if (data->nb_philos > 1)
	{
		if (pthread_create(&data->kill_phil, NULL, &kill_phil, data) != 0)
			return (error_mem(ERROR_THREAD, NULL, data));
	}
	return (true);
}

//espera a que se unan todos los subprocesosy libera la memoria
//inicia tambien la funcion kill_phill
static void	stop(t_lunch *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
	if (data->nb_philos > 1)
		pthread_join(data->kill_phil, NULL);
	destroy_mutexes(data);
	free_data(data);
}

/* Se crea la estructura data que es donde se encuentran
	-los datos principales de iniciacion	
	-se inicializa en null.
	-se comprueba que no haya al menos 4 argumentos y mas de 5 
	-valida los argumentos que sean digitos y que esten entre 1 y 
	-el maximo de filosofos
	-inicia la estructura data*/

int	main(int ac, char **av)
{
	t_lunch	*data;

	data = NULL;
	if (ac - 1 < 4 || ac - 1 > 5)
		return (errormsg(ERROR_ARGS, NULL, EXIT_FAILURE));
	if (!valid_input(ac, av))
		return (EXIT_FAILURE);
	data = init_lunch(ac, av, 1);
	if (!data)
		return (EXIT_FAILURE);
	if (!start(data))
		return (EXIT_FAILURE);
	stop(data);
	return (EXIT_SUCCESS);
}
