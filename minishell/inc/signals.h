/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:23:34 by mariza            #+#    #+#             */
/*   Updated: 2023/11/08 09:18:58 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "error.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>

void	handle_sigint(int sig);
void	signal_handle(void);
void	signal_here_handle(void);

#endif