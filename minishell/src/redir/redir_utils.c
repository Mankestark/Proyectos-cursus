/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:31:55 by mariza            #+#    #+#             */
/*   Updated: 2023/09/19 00:37:51 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/executor.h"

void	backup_std(int backup_fds[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		backup_fds[i] = dup(i);
		if (backup_fds[i] == -1)
		{
			perror("dup");
			exit(1);
		}
		i++;
	}
}

void	restore_std(int backup_fds[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (dup2(backup_fds[i], i) == -1)
		{
			perror("dup2");
			exit(1);
		}
		close(backup_fds[i]);
		i++;
	}
}
