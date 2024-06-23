/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:55:48 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/09 19:27:39 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Semantic Token List
 */
#ifndef STL_H
# define STL_H

# include <stdlib.h>
# include "data.h"
# include "error.h"

/**
 * @brief Enumerated for token type
 *
 *	- command_tkn:		(Text) Command or script.
 *	- argument_tkn:		(Text) Argument of the command or script.
 *	- stream_tkn:		(Text) File or data stream used in the redirections.
 *	- write_tkn:		('>') Standard output redirection with overwrite.
 *	- append_tkn:		('>>') Standard output redirection without overwriting.
 *	- read_tkn:			('<') Standard input redirection.
 *	- delimiter_tkn:	('<<') Input redirection with delimiter.
 *	- pipe_tkn:			('|') Pipeline operator to connect processes.
 */
typedef enum e_tkn_type
{
	unknown_tkn,
	command_tkn,
	argument_tkn,
	stream_tkn,
	write_tkn,
	append_tkn,
	read_tkn,
	delimiter_tkn,
	pipe_tkn
}	t_tkn_type;

/** @struct s_stlist
 * @brief Struct storing tokens with semantic meaning
 *
 * @var s_stlist::token		Token content (char *).
 * @var s_stlist::type		Type of token (t_tkn_type).
 * @var s_stlist::next		Next list item (s_list *).
 */
typedef struct s_stlist {
	char			*token;
	t_tkn_type		type;
	struct s_stlist	*next;
}	t_stlist;

t_error	stl_add(t_stlist **list, char *token, t_tkn_type type);
void	stl_free(t_stlist **list);
int		stl_is_pipe(t_stlist *node);
int		stl_is_redir(t_stlist *node);
int		stl_is_text(t_stlist *node);

#endif
