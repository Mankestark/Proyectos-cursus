/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_toolkit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:44:24 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/28 16:37:24 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Abstract Syntax Tree Toolkit
 */
#ifndef AST_TOOLKIT_H
# define AST_TOOLKIT_H

# include "ast.h"
# include "data.h"
# include "error.h"
# include "stl_toolkit.h"
# include "environ.h"

/**
 * @brief	Text quotes states
 *
 *	- error_state:		Syntactic error status. It occurs when an unexpected
 						char is received.
 *	- def_state:		Default state
 *	- sng_state:		Current char is inside single quotes
 *	- variable_state:	Current char is part of a variable name
 *	- dbl_state:		Current char is inside double quotes
 						quotes
 */
typedef enum e_quote_state
{
	error_qstate,
	def_qstate,
	sng_qstate = 2,
	dbl_qstate = 4,
	variable_qstate = 8
}	t_quote_state;

int		ast_delim_len(char *text);
char	*ast_delim_value(char *text, int len);
t_error	ast_expand(t_astree *tree, t_environ *environ, int return_code);
t_error	ast_generate(t_astree **tree, t_stlist *list);
t_error	ast_new_command_node(t_astree **new_node, t_stlist **list);
t_error	ast_parse(t_astree **tree, char *input, t_environ *environ,
			int return_code);
int		ast_text_len(char *text, t_environ *environ, int return_code);
char	*ast_text_value(char *text, int len, t_environ *environ,
			int return_code);

#endif
