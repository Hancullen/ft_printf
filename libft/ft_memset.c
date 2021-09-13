/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:38:49 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/27 20:44:38 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*dst;

	dst = ptr;
	while (n > 0)
	{
		*dst = (unsigned char) x;
		dst++;
		n--;
	}
	return (ptr);
}
