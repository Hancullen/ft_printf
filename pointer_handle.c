/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 23:36:05 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/20 14:34:25 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_conversion(t_flag flag, char *str, unsigned long long num)
{
	unsigned long long	i;

	i = 0;
	if (flag.type == 'p' && num == 0 && flag.dot == 0)
		str[i++] = '0';
	while (num)
	{
		if ((num % 16) < 10)
			str[i++] = num % 16 + '0';
		else
			str[i++] = (num % 16) - 10 + 'a';
		num = num / 16;
	}
	if (flag.type == 'p')
	{
		str[i++] = 'x';
		str[i++] = '0';
	}
	str[i] = 0;
	return (str);
}

char	*ptr_blank_padding(t_flag flag, int len, char *str)
{
	char	*s;

	if (flag.minus != 1)
		s = left_blank_str(flag, str, len);
	else
		s = right_blank_str(flag, str, len);
	return (s);
}

int	ptr_handle(t_flag flag, va_list ap)
{
	char				*str;
	char				*ptr;
	int					len;
	unsigned long long	num;

	str = ft_calloc(17, 1);
	num = va_arg(ap, unsigned long long);
	str = hex_conversion(flag, str, num);
	len = ft_strlen(str);
	if (len == 0)
	{
		if (flag.precision == 0)
			return (0);
	}
	else
	{
		ptr = ptr_blank_padding(flag, len, str);
		if (!ptr)
			return (0);
		print_str(flag, ptr, ft_strlen(ptr));
	}
	free(str);
	return (1);
}
