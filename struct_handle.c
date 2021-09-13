/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:49:53 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/23 16:38:19 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*width_handle(t_flag *flag, const char *start, va_list ap)
{
	const char	*ptr;

	ptr = start;
	if (*ptr == '*')
	{
		flag->width = va_arg(ap, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus = 1;
		}
		ptr++;
	}
	else
	{
		while (ft_isdigit(*ptr))
		{
			flag->width = flag->width * 10 + (*ptr - '0');
			ptr++;
		}
	}
	return (ptr);
}

const char	*precision_handle(t_flag *flag, const char *start, va_list ap)
{
	const char	*ptr;
	int			len;

	flag->dot = 1;
	len = 0;
	ptr = start + 1;
	if (*ptr == '*')
	{
		flag->precision = va_arg(ap, int);
		if (flag->precision < 0)
			flag->star = 1;
		ptr++;
	}
	else
	{
		while ((ft_isdigit(*ptr)) && (flag->type != 'c' && flag->type != '%'))
		{
			len = len * 10 + (*ptr - '0');
			ptr++;
			flag->precision = len;
		}
	}
	return (ptr);
}

int	type_decision(t_flag flag, va_list ap)
{
	char	c;
	int		printed;

	c = flag.type;
	printed = 0;
	if (c == 'c')
		printed = char_handle(flag, ap);
	else if (c == 's')
		printed = str_handle(flag, ap);
	else if (c == 'p')
		printed = ptr_handle(flag, ap);
	else if (c == '%')
		printed = percent_handle(flag);
	else
		printed = num_handle(flag, ap);
	return (printed);
}

const char	*ft_format(const char *start, va_list ap)
{
	const char	*result;
	t_flag		flag;

	result = start;
	flag_init(&flag);
	while (*result == '-' || *result == '0')
	{
		if (*result == '-')
			flag.minus = 1;
		else
			flag.zero = 1;
		result++;
	}
	result = width_handle(&flag, result, ap);
	if (*result == '.')
		result = precision_handle(&flag, result, ap);
	if (!is_conversion(*result))
		return (NULL);
	flag.type = *result;
	if (!type_decision(flag, ap))
		return (NULL);
	return (result);
}
