/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:22:35 by mariza            #+#    #+#             */
/*   Updated: 2022/11/12 18:12:05 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE	1024
# define OPEN_MAX		255

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int				ft_isalnum(int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strstr(char *haystack, char *needle);
int		ft_gnl(int fd, char **line);
void	*ft_strcpy_gnl(char *dst, char *src, size_t n);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
unsigned int	ft_strlen(const char *str);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
char			*ft_strchr(const char *str, int c);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_bzero(void *str, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
char			*ft_itoa(int n);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putcharacter_length(char character, int *length);
void			ft_string(char *args, int *length);
void			ft_number(int number, int *length);
void			ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void			ft_unsigned_int(unsigned int u, int *length);
void			ft_pointer(size_t pointer, int *length);
int				ft_printf(const char *string, ...);

#endif
