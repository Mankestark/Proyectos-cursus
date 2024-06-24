/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:49:45 by mariza            #+#    #+#             */
/*   Updated: 2023/10/09 01:41:41 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "data.h"
# include "error.h"
# include "libft.h"

// Estructura para almacenar los tokens
typedef struct s_tokens
{
	char			*token;
	struct s_tokens	*next;
}					t_tokens;

t_error	add_token(t_tokens **list, char *word);
void	free_list(t_tokens **list);
int		ft_isspace(int c);
t_error	handle_normal_token(t_tokens **list,
			char *command_line,
			int length,
			int *init_word);
t_error	handle_special_char(t_tokens **list,
			char *command_line,
			int *init_word);
int		is_special_char(char c);
t_error	split_tokens(t_tokens **list, char *comand_line,
			int final_word, int init_word);
t_error	tokenizer(t_tokens **list, char *comand_line);

#endif
