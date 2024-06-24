/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:56:00 by jmorillo          #+#    #+#             */
/*   Updated: 2023/10/15 20:24:01 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ast.h"

static void	ast_free_arg(t_arg_node *node);
static void	ast_free_cmd(t_cmd_node *node);
static void	ast_free_redir(t_redir_node *node);

void	ast_free(t_astree **root)
{
	if (!root || !(*root))
		return ;
	if ((*root)->type == command_tkn)
		ast_free_cmd((*root)->cmd);
	ast_free(&(*root)->next);
	ast_free(&(*root)->child);
	ft_free((void **)root);
}

static void	ast_free_cmd(t_cmd_node *node)
{
	if (!node)
		return ;
	ft_free((void **)&node->text);
	ast_free_arg(node->args);
	ast_free_redir(node->redir);
	ft_free((void **)&node);
}

static void	ast_free_arg(t_arg_node *node)
{
	if (!node)
		return ;
	ast_free_arg(node->next);
	ft_free((void **)&node->text);
	ft_free((void **)&node);
}

static void	ast_free_redir(t_redir_node *node)
{
	if (!node)
		return ;
	ast_free_redir(node->next);
	ft_free((void **)&node->text);
	ft_free((void **)&node);
}
