/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:49:45 by mariza            #+#    #+#             */
/*   Updated: 2023/10/29 08:15:24 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "data.h"
# include "error.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void			*ft_calloc(size_t count, size_t size);
void			ft_free(void **pointer);
void			ft_free_array(char ***pointer_to_array);
int				ft_is_alpha(char c);
int				ft_is_alphanum(char c);
char			*ft_itoa(int n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
int				ft_num_len(int n);
void			ft_putstr_fd(char *s, int fd);
void			*ft_realloc(void *ptr, size_t size);
int				ft_str_cmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
unsigned int	ft_strlen(const char *str);
char			*ft_strncpy(char *s1, char *s2, int n);
char			*ft_strrchr(const char *cmd, int character);
int				ft_atoi(const char *str);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
