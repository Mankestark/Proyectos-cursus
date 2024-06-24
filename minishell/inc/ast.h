/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:43:25 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/30 18:38:28 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Abstract Syntax Tree
 */
#ifndef AST_H
# define AST_H

# include "data.h"
# include "error.h"
# include "libft.h"
# include "stl.h"
# include <stdlib.h>

typedef struct s_arg_node
{
	char				*text;
	struct s_arg_node	*next;
}						t_arg_node;

typedef struct s_redir_node
{
	int					type;
	char				*text;
	struct s_redir_node	*next;
}						t_redir_node;

typedef struct s_cmd_node
{
	char				*text;
	t_arg_node			*args;
	t_redir_node		*redir;
}						t_cmd_node;

typedef struct s_astree
{
	int					type;
	t_cmd_node			*cmd;
	struct s_astree		*next;
	struct s_astree		*child;
}						t_astree;

t_error					ast_add_arg(t_astree *node, char *text);
t_error					ast_add_child(t_astree *node, t_astree *child);
t_error					ast_add_redir(t_astree *node, int type, char *text);
t_error					ast_add_sibling(t_astree *node, t_astree *sibling);
int						ast_arg_count(t_astree *node);
int						ast_child_count(t_astree *node);
t_astree				*ast_create(int type, t_error *error);
void					ast_free(t_astree **root);
int						ast_is_cmd(t_astree *node);
int						ast_is_pipe(t_astree *node);
int						ast_pipe_heredoc_count(t_astree *node);
int						ast_redir_count(t_astree *node);
int						ast_child_redir_count(t_astree *node);
int						ast_sibling_count(t_astree *node);

#endif
