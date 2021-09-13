/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 00:04:18 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/18 17:43:57 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*str_padding_handle(t_flag *flag, va_list ap)
{
	char	*src;
	char	*dst;
	int		len;

	src = va_arg(ap, char *);
	if (!src)
		src = NULLSTR;
	len = ft_strlen(src);
	dst = ft_calloc(len + 1, 1);
	if (flag->star)
		flag->precision = len;
	if (flag->precision < len && flag->precision > 0)
	{
		src = ft_strncpy(dst, src, flag->precision);
		len = ft_strlen(src);
	}
	if (flag->width > len)
		len = flag->width;
	if (flag->minus)
		src = right_blank_padding(*flag, len, src);
	else if (!flag->minus)
		src = left_blank_padding(*flag, len, src);
	free(dst);
	return (src);
}

int	str_handle(t_flag flag, va_list ap)
{
	char	*result;
	int		len;

	if (flag.zero)
		return (0);
	if ((flag.dot && flag.precision == -1 && flag.star == 0)
		|| (flag.precision == 0))
	{
		len = flag.width;
		va_arg(ap, char *);
		while (len--)
		{
			write(1, " ", 1);
			g_count++;
		}
		return (1);
	}
	result = str_padding_handle(&flag, ap);
	if (!result)
		return (0);
	print_str(flag, result, ft_strlen(result));
	return (1);
}
