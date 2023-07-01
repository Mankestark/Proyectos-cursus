/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papa <papa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:30:43 by mariza            #+#    #+#             */
/*   Updated: 2023/06/30 11:17:15 by papa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOS	200
# define STR_MAX_PHILOS "200"

//mensajes de error 
# define ERROR_MALLOC "%s No se pudo asignar memoria\n"
# define ERROR_THREAD "%s No se pudo crear el hilo\n"
# define ERROR_MUTEX "%s No se pudo crear el mutex\n"
# define ERROR_MAXMINPHIL "%s Error tiene que haber entre 1 y 200 filosofos\n"
# define ERROR_INTEGER "%s Error tiene que ser entero\n"
# define ERROR_ARGS "%s Error en los argumentos\n"
# define ERROR_DIGIT "El argumento no es un digito\n"

typedef struct s_philo	t_philo;

//start_time tiempo de comienzo de la simulacion
//nb_philos numero de filosofos
//time_to_die tiempo para morir
//time_to_eat tiempo para comer
//time_to_sleep tiempo para dormir
//must_eat_count numero de veces que van a comer
//sim_stop detencion de la simulacion
//**philos enlace a la estructura t_philo
//fork_locks mutex para los tenedores
typedef struct s_data
{
	time_t				start_time;
	unsigned int		nb_philos;
	pthread_t			kill_phil;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					must_eat_count;
	bool				sim_stop;
	pthread_mutex_t		sim_stop_lock;
	pthread_mutex_t		write_lock;
	t_philo				**philos;
	pthread_mutex_t		*fork_locks;
}						t_lunch;

//thread hilo del filosofo
//id identificacion del filosofo
//fork[2] numero de tenedores
//meal_time_lock mutex asignado al tiempo de comida
//last_meal tiempo de inicio del filosofo coincide con el de la simulacion
typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				last_meal;
	t_lunch				*data;
}						t_philo;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}						t_status;

int						check_args(int ac, char **av);
bool					valid_input(int ac, char **av);
int						int_atoi(char *str);
t_lunch					*init_lunch(int ac, char **av, int i);
void					*philosopher(void *data);
time_t					get_time_in_ms(void);
void					philo_sleep(t_lunch *data, time_t sleep_time);
void					sim_start_delay(time_t start_time);
void					write_status(t_philo *philo, bool reaper,
							t_status status);
int						error_mem(char *str, char *det, t_lunch *data);
void					*error_init(char *str, char *det, t_lunch *data);
void					*free_data(t_lunch *data);
void					*kill_phil(void *data);
bool					has_simulation_stopped(t_lunch *data);
void					destroy_mutexes(t_lunch *data);
int						errormsg(char *str, char *det, int exitnumb);

#endif