/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:17:32 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/04 23:33:18 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_init(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->star = 0;
	flag->precision = -1;
	flag->neg_num = 0;
	flag->type = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	g_count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			g_count++;
		}
		else
		{
			format = ft_format(format + 1, ap);
			if (!format)
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (g_count);
}
