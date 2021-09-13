/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:04:13 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/27 20:39:38 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*end;

	end = 0;
	while (*str)
	{
		if (*str == c)
		{
			end = (char *) str;
		}
		str++;
	}
	if (!c)
		return ((char *) str);
	return (end);
}
