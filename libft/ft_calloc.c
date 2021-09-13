/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:40:32 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/25 22:04:18 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	sz;

	if (size == 0)
		sz = count;
	else
		sz = count * size;
	ptr = malloc(sz);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, sz);
	return (ptr);
}
