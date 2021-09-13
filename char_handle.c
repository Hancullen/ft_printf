/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:32:39 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/05 23:54:06 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_blank_padding(t_flag flag, int len, char c)
{
	char	*str;

	if (!flag.minus)
		str = left_blank_padding(flag, len, &c);
	else
		str = right_blank_padding(flag, len, &c);
	return (str);
}

int	char_handle(t_flag flag, va_list ap)
{
	char	*s;
	char	c;
	int		len;

	len = 0;
	c = va_arg (ap, int);
	if (flag.precision != -1 || flag.zero)
		return (0);
	if (flag.width == 0)
	{
		ft_putchar_fd(c, 1);
		g_count++;
	}
	else
	{
		len += flag.width;
		s = char_blank_padding(flag, len, c);
		if (!s)
			return (0);
		print_str(flag, s, len);
	}
	return (1);
}
