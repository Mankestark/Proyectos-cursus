/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:53:14 by mariza            #+#    #+#             */
/*   Updated: 2023/11/08 09:14:21 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"
#include "../../inc/redir.h"

static void	create_temp_file(char *temp_file, int fd_doc)
{
	fd_doc = open(temp_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_doc == -1)
	{
		ft_putstr_fd("Error al crear el archivo temporal\n", 2);
		exit(1);
	}
	close(fd_doc);
}

static void	redirect_stdin_to_temp(char *temp_filename, int fd)
{
	close(fd);
	fd = open(temp_filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo temporal");
		return ;
	}
	dup2(fd, 0);
	return ;
}

static void	remove_temp_file(char *temp_file)
{
	unlink(temp_file);
}

static void	write_line_to_temp(const char *line, char *temp_file, int fd_doc)
{
	char	newline;

	fd_doc = open(temp_file, O_WRONLY | O_APPEND);
	if (fd_doc == -1)
	{
		ft_putstr_fd("Error al abrir el archivo temporal\n", 2);
		exit(1);
	}
	if (write(fd_doc, line, ft_strlen(line)) == -1)
	{
		ft_putstr_fd("Error al escribir en el archivo temporal\n", 2);
		exit(1);
	}
	newline = '\n';
	if (write(fd_doc, &newline, 1) == -1)
	{
		ft_putstr_fd("Error al escribir newline en temp\n", 2);
		exit(1);
	}
}

int	heredoc(int fd_doc, t_check_heredoc *check)
{
	t_heredoc	heredoc;

	heredoc.temp_filename = "heredoc_temp.temp";
	create_temp_file(heredoc.temp_filename, fd_doc);
	heredoc.current_arg = 0;
	heredoc.input = NULL;
	signal_here_handle();
	while (heredoc.current_arg < check->delimiter_count)
	{
		free(heredoc.input);
		heredoc.input = readline("> ");
		if ((heredoc.input) == NULL || g_data.state == -42)
			break ;
		if (ft_str_cmp(heredoc.input,
				check->here_split[heredoc.current_arg]) == 0)
			heredoc.current_arg++;
		else if (heredoc.current_arg == (check->delimiter_count - 1))
			write_line_to_temp(heredoc.input, heredoc.temp_filename, fd_doc);
	}
	free(heredoc.input);
	redirect_stdin_to_temp(heredoc.temp_filename, fd_doc);
	remove_temp_file(heredoc.temp_filename);
	free_heredoc_content(check);
	return (0);
}
