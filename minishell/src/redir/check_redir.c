/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:03:19 by mariza            #+#    #+#             */
/*   Updated: 2023/11/07 00:22:03 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/redir.h"

static int	ft_file_err(const char *file)
{
	struct stat	buf;

	if (stat(file, &buf) == -1)
	{
		if (S_ISDIR(buf.st_mode))
		{
			print_errors(is_direct, NULL, 1);
			return (1);
		}
		else if ((buf.st_mode & S_IXUSR) == 0)
		{
			print_errors(not_permission, NULL, 1);
			return (1);
		}
	}
	print_errors(not_file, NULL, 1);
	return (1);
}

// funcion para la redireccion <
static int	read_redir(const char *file, int fd)
{
	close(fd);
	fd = open(file, O_RDONLY, S_IRWXU);
	if (fd == -1)
	{
		ft_file_err(file);
		return (1);
	}
	dup2(fd, 0);
	return (0);
}

// Funcion para la redireccion >
static int	write_redir(const char *file, int fd)
{
	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT | O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_file_err(file);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	append_redir(const char *file, int fd)
{
	fd = open(file, O_WRONLY | O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_file_err(file);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void	check_redir(t_cmd_node *cmd, int *result, int *type_redir)
{
	t_redir_node	*redir;
	t_redir			red;

	red.fd_in = 0;
	red.fd_out = 1;
	redir = cmd->redir;
	while (redir)
	{
		if (redir->type == 6)
			*result = read_redir(redir->text, red.fd_in);
		else if (redir->type == 4)
			*result = write_redir(redir->text, red.fd_out);
		else if (redir->type == 5)
			*result = append_redir(redir->text, red.fd_out);
		*type_redir = redir->type;
		redir = redir->next;
	}
	*type_redir = 0;
}
