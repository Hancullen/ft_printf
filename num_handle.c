/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:40:56 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/19 13:10:15 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_base(t_flag *flag, long long num, int base, char *result)
{
	int	i;

	i = 0;
	if ((num == 0 && flag->star) || (num == 0 && !flag->dot))
		result[i++] = '0';
	if (num < 0)
	{
		flag->neg_num = 1;
		num *= -1;
		if (flag->dot)
			flag->precision++;
	}
	if (num != 0 && base == 16)
		result = hex_conversion(*flag, result, num);
	else
	{
		while (num)
		{
			result[i++] = num % 10 + '0';
			num = num / 10;
		}
		result[i] = 0;
	}
	return (result);
}

char	*num_paddling_handle(t_flag flag, char *str)
{
	char	*result;
	int		len;

	len = ft_strlen(str);
	result = 0;
	if (flag.precision >= 0)
	{
		if (flag.minus)
			result = right_blank_num(flag, len, str);
		else if (flag.star && flag.zero)
			result = left_zero_num(flag, len, str);
		else
			result = left_blank_num(&flag, len, str);
	}
	else
	{
		if (flag.minus)
			result = right_blank_num(flag, len, str);
		else if (flag.zero && (flag.star || flag.neg_num || !flag.dot))
			result = left_zero_num(flag, len, str);
		else
			result = left_blank_num(&flag, len, str);
	}
	return (result);
}

int	num_handle(t_flag flag, va_list ap)
{
	long long	num;
	char		*result;
	char		*temp;

	temp = ft_calloc(11, 1);
	if ((flag.type == 'd') || (flag.type == 'i'))
	{
		num = (int) va_arg(ap, int);
		temp = itoa_base(&flag, num, 10, temp);
	}
	else
	{
		num = (long long) va_arg(ap, unsigned int);
		if (flag.type == 'x' || flag.type == 'X')
			temp = itoa_base(&flag, num, 16, temp);
		else
			temp = itoa_base(&flag, num, 10, temp);
	}
	result = num_paddling_handle(flag, temp);
	if (!result)
		return (0);
	free(temp);
	print_str(flag, result, ft_strlen(result));
	return (1);
}
