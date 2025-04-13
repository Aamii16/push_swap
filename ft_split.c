/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:51:36 by amzahir           #+#    #+#             */
/*   Updated: 2025/04/13 01:46:47 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**getsplit(char const *s, char c, int *count, size_t *i)
{
	char	**split;

	if (!s)
		return (NULL);
	*i = 0;
	*count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		(*count)++;
	}
	split = malloc(((*count) + 1) * sizeof(char *));
	return (split);
}

static int	wordsize(const char *s, char c, size_t *i)
{
	size_t	w_size;

	w_size = 0;
	while (s[*i] == c && s[*i])
		(*i)++;
	while (s[*i] != c && s[*i])
	{
		(*i)++;
		w_size++;
	}
	return (w_size);
}

static void	free_pt(char **split, int e)
{
	if (!split)
		return ;
	while (e >= 0)
	{
		free(split[e]);
		e--;
	}
	free(split);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	w_size;
	int		e;
	int		elements;
	char	**split;

	e = -1;
	split = getsplit(s, c, &elements, &i);
	if (!split)
		return (NULL);
	while (s[i] && e < elements + 1)
	{
		w_size = wordsize(s, c, &i);
		if (!w_size)
			break ;
		split[++e] = malloc((w_size + 1) * sizeof(char));
		if (!split[e])
		{
			free_pt(split, e);
			return (NULL);
		}
		ft_strlcpy(split[e], s + i - w_size, w_size + 1);
	}
	split[e + 1] = NULL;
	return (split);
}
