/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:02:36 by jmorillo          #+#    #+#             */
/*   Updated: 2023/11/09 21:27:40 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/**
 * @brief Enumerated for error control
 *		no_error: everything is OK
 *		quote_err: mismatched quotation marks
 *		parenthesis_err: mismatched parentheses
 *		syntax_err: syntax error on the command line
 *		mem_alloc_err: failure to allocate dynamic memory
 *		operator_err: use of a non-allowed operator
 *		identifier_err: invalid identifier
 * 		null_pointer_err: argument is NULL
 * 		not_file: not file exist
 * 		not_cmd: not command found
 * 		err_cmd: error in command
 *
 */

# include "data.h"
# include "libft.h"

typedef enum e_error
{
	no_error,
	quote_err,
	parenthesis_err,
	syntax_err,
	mem_alloc_err,
	operator_err,
	identifier_err,
	null_pointer_err,
	not_file,
	not_cmd,
	err_cmd,
	too_many_args,
	not_permission,
	is_direct
}		t_error;

void	*print_errors(int type_error, char *param, int status_err);
void	print_error_and_exit(t_error error, int code);

#endif
