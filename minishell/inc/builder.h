/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:59 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 11:13:22 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDER_H
# define BUILDER_H

# include "ast.h"
# include "ast_toolkit.h"
# include "builder.h"
# include "data.h"
# include "environ.h"
# include "error.h"
# include "libft.h"
# include "redir.h"
# include "stl.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_exprt
{
	char	*variable;
	char	*value;
	char	*input;
	int		result;

}			t_exprt;

int			execute_builds(t_astree *tree, t_environ **env, int type_redir);
int			conchi_pwd(t_environ *env);
int			conchi_echo(t_arg_node *comands, int type_redir);
int			conchi_env(t_environ *env);
int			conchi_unset(t_arg_node *args, t_environ **env);
int			conchi_cd(t_arg_node *args, t_environ *env);
int			conchi_export(t_arg_node *args, t_environ **env);
int			conchi_exit(t_astree *tree, t_arg_node *args, t_environ *envs);
#endif
