/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:28:41 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/05 00:02:56 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conversion(char c)
{
	char	*str;

	str = TYPE;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	digit_length(int n)
{
	int	length;

	if (n == -2147483648)
		return (11);
	length = 0;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n / 10)
	{
		length++;
		n = n / 10;
	}
	length++;
	return (length);
}
