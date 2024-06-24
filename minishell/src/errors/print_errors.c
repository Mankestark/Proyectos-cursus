/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:33:21 by mariza            #+#    #+#             */
/*   Updated: 2023/11/09 20:09:51 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"

void	*print_errors(int type_error, char *param, int status_err)
{
	g_data.state = status_err;
	if (type_error == quote_err)
		ft_putstr_fd("Error while looking for matching quote\n", 2);
	else if (type_error == not_file)
		ft_putstr_fd("No such file or directory \n", 2);
	else if (type_error == not_cmd)
		ft_putstr_fd("Command not found\n", 2);
	else if (type_error == not_permission)
		ft_putstr_fd("Permission denied\n", 2);
	else if (type_error == syntax_err)
		ft_putstr_fd("Syntax error on the command line\n", 2);
	else if (type_error == mem_alloc_err)
		ft_putstr_fd("Failure to allocate dynamic memory\n", 2);
	else if (type_error == operator_err)
		ft_putstr_fd("Use of a non-allowed operator\n", 2);
	else if (type_error == identifier_err)
		ft_putstr_fd("Invalid identifier\n", 2);
	else if (type_error == null_pointer_err)
		ft_putstr_fd("Argument is NULL\n", 2);
	else if (type_error == err_cmd)
		ft_putstr_fd("Error in command\n", 2);
	else if (type_error == too_many_args)
		ft_putstr_fd("too many arguments\n", 2);
	ft_putstr_fd(param, 2);
	return (NULL);
}
