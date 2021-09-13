/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:50:10 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/27 21:55:56 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(const char *s, char c)
{
	int	count;
	int	i;

	if (s == 0 || s[0] == 0)
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **s, int j)
{
	int	i;

	i = 0;
	while (s[i] && i < j)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	ft_word_count(const char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_fill_arr(char const *src, char **res, char c)
{
	int		idx;
	int		j;
	int		k;

	idx = 0;
	j = -1;
	while (++j < ft_str_count(src, c))
	{
		k = 0;
		res[j] = malloc(ft_word_count(src, c, idx) + 1);
		if (res[j] == NULL)
			ft_free(res, j);
		while (src[idx] && src[idx] == c)
			idx++;
		while (src[idx] && src[idx] != c)
		{
			res[j][k++] = src[idx++];
		}
		res[j][k] = '\0';
	}
	res[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((ft_str_count(s, c) + 1) * sizeof(char *));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	res[ft_str_count(s, c)] = 0;
	ft_fill_arr(s, res, c);
	return (res);
}
