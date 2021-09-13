/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:56:10 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/31 14:37:02 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_s1;
	char	*p;
	size_t	i;

	copy_s1 = 0;
	i = 0;
	while (s1[i])
	{
		i++;
	}
	copy_s1 = malloc((i + 1) * sizeof(char));
	if (!copy_s1)
		return (NULL);
	p = copy_s1;
	p = ft_memcpy(p, s1, i + 1);
	return (copy_s1);
}
