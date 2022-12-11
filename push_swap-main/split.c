/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:00:36 by mariza            #+#    #+#             */
/*   Updated: 2022/12/11 18:04:28 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_words(const char *str, char c)
{
	int	words;

	words = 0;
	if (*str != c && *str)
		words++;
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				words++;
		}
		str++;
	}
	return (words);
}

static int	letters(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static char	**allocate_tab(char const *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 2));
	if (!s || (!(tab)))
		return (NULL);
	tab[0] = ft_strnew(1);
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	j = 1;
	i = 0;
	tab = allocate_tab(s, c);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[j] = (char *)ft_calloc(sizeof(char), (letters(s, c) + 1));
			if (!(tab[j]))
				return (NULL);
			while (*s && *s != c)
				tab[j][i++] = (char)*s++;
			j++;
			i = 0;
		}
	}
	tab[j] = NULL;
	return (tab);
}

int	ft_tab_size(char **tab)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (tab[i])
	{
		size++;
		i++;
	}
	return (size);
}
