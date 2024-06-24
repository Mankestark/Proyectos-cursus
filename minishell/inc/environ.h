/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:13:52 by jmorillo          #+#    #+#             */
/*   Updated: 2023/09/30 19:05:49 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Environment Variables Dictionary
*/
#ifndef ENVIRON_H
# define ENVIRON_H

# include "error.h"
# include "data.h"
# include "libft.h"
# include <stdlib.h>

typedef struct s_environ
{
	char				*name;
	char				*value;
	struct s_environ	*next;
}						t_environ;

void		evd_free(t_environ **env);
char		*evd_get(t_environ *env, char *name);
int			evd_is_valid(char *identifier);
t_environ	*evd_load(char **envp, t_error *error);
void		evd_remove(t_environ **env, char *name);
char		**evd_save(t_environ *environ, t_error *error);
t_error		evd_set(t_environ **env, char *name, char *value);

#endif
