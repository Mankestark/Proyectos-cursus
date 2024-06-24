/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_toolkit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:27:00 by jmorillo          #+#    #+#             */
/*   Updated: 2023/09/03 20:19:18 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Sematic Token List Toolkit
*/
#ifndef STL_TOOLKIT_H
# define STL_TOOLKIT_H

# include "error.h"
# include "lexer.h"
# include "data.h"
# include "stl.h"

/**
 * @brief	Token analysis states
 *
 *	- error_state:		Syntactic error status. It occurs when an unexpected
 						token is received.
 *	- default_state:	Default state
 *	- command_state:	Current token is a command
 *	- argument_state:	Current token is an argument
 *	- stream_state:		Current token is a file or data stream
 *	- redir_state:		Current token is a redirection
 *	- close_state:		Current token is a closing parenthesis
 */
typedef enum e_tkn_state
{
	error_state,
	default_state,
	command_state = 2,
	argument_state = 4,
	stream_state = 8,
	redir_state = 16,
	close_state = 32
}	t_tkn_state;

t_error		stl_analysis(t_stlist **list, t_tokens *tokens);
t_tkn_type	stl_guess_type(t_stlist *list, char *token);

#endif
