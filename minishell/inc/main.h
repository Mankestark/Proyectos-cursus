/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:38:12 by mariza            #+#    #+#             */
/*   Updated: 2023/10/12 12:29:59 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ast_toolkit.h"
# include "builder.h"
# include "data.h"
# include "environ.h"
# include "error.h"
# include "executor.h"
# include "lexer.h"
# include "redir.h"
# include "signals.h"
# include "stl.h"
# include "stl_toolkit.h"
# include "readline/history.h"
# include "readline/readline.h"

typedef struct s_main
{
	t_astree	*tree;
	char		*txt;
	t_error		error;
	t_environ	*env;
	int			result;
}				t_main;

#endif
