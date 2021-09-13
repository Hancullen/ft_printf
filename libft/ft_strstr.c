/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:03:57 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/22 13:28:26 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*start;
	const char	*to_find;

	if (*needle == '\0')
	{
		start = (char *) haystack;
		return (start);
	}
	while (*haystack)
	{
		start = (char *) haystack;
		to_find = needle;
		while (*to_find && *haystack == *to_find)
		{
			to_find++;
			haystack++;
		}
		if (*to_find == '\0')
			return (start);
		haystack = start + 1;
	}
	return (0);
}
