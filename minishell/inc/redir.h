/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:42:41 by mariza            #+#    #+#             */
/*   Updated: 2023/11/08 09:08:36 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "ast.h"
# include "data.h"
# include "error.h"
# include "libft.h"
# include "main.h"
# include "stl.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_redir
{
	int		result;
	int		fd_in;
	int		fd_out;
	int		type_redir;
}			t_redir;

typedef struct s_heredoc
{
	char	*input;
	char	*temp_filename;
	int		flag;
	int		*ptr_flag;
	int		current_arg;
}			t_heredoc;

typedef struct s_check_heredoc
{
	char	**here_split;
	int		delimiter_count;
}			t_check_heredoc;

void		check_redir(t_cmd_node *cmd, int *result, int *type_redir);
void		restore_std(int backup_fds[3]);
void		backup_std(int backup_fds[3]);
int			heredoc(int fd_doc, t_check_heredoc *check);
int			add_heredoc(char *content, t_check_heredoc *check);
void		free_heredoc_content(t_check_heredoc *check);
int			check_heredoc(t_astree *tree, t_check_heredoc *check);
int			execute_heredoc(void);
void		signal_here_handle(void);

#endif