/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:07:38 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/25 07:04:53 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d_end;
	const char	*s;

	d_end = dst + size;
	s = src;
	while (*s != '\0' && dst < d_end)
		*dst++ = *s++;
	if (dst < d_end)
		*dst = 0;
	else if (size > 0)
		dst[-1] = 0;
	while (*s)
		s++;
	return (s - src);
}
