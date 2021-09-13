/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:36:07 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/31 15:21:19 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_helper(const char *str, int i, int sign)
{
	unsigned long long	num;

	num = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (i >= 19)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\a'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1 * sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = ft_helper(str, i, sign);
	return (result);
}
