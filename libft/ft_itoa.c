/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:18:38 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/31 07:26:59 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int c)
{
	int	len;

	len = 0;
	if (c <= 0)
	{
		len++;
	}
	while (c != 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

static void	ft_fill_str(char *result, int c, int len, int pre_fill)
{
	while (len > pre_fill)
	{
		result[len - 1] = '0' + c % 10;
		c = c / 10;
		len--;
	}
}

char	*ft_itoa(int c)
{
	char	*result;
	int		pre_fill;
	int		len;

	len = ft_int_len(c);
	pre_fill = 0;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	if (c == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		pre_fill = 2;
		c = 147483648;
	}
	if (c < 0)
	{
		result[0] = '-';
		pre_fill = 1;
		c = -c;
	}
	ft_fill_str(result, c, len, pre_fill);
	result[len] = '\0';
	return (result);
}
