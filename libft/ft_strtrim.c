/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:43:51 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/28 17:28:22 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchar(char const *s1, char c)
{
	if (!s1)
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	begin;
	size_t	end;
	size_t	i;

	begin = 0;
	while (s1[begin] && ft_strchar(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_strchar(set, s1[end - 1]))
		end--;
	p = malloc((end - begin) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (begin < end)
	{
		p[i++] = s1[begin++];
	}
	p[i] = '\0';
	return (p);
}

/*
** This is a different view of how a string trim function work.
** This function produced completely different bahvior
** from ft_strtrim's requirements.
** It trimmed the "set" at any position in s1.

**char	*ft_strtrim(char const *s1, char const *set)
**{
**	char	*p;
**	size_t	len;
**
**	len = ft_strlen(set);
**	if (len > 0)
**	{
**		p = (char *) s1;
**		p = ft_strstr(p, set);
**		if (p)
**		{
**			ft_memmove(p, p + len, ft_strlen(p + len) + 1);
**		}
**	}
**	return ((char *) s1);
**}
*/
