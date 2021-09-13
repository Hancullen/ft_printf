/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 13:56:10 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/23 15:39:34 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*percent_padding(t_flag flag, int len)
{
	char	*result;
	char	c;

	c = '%';
	if (!flag.minus && !flag.zero)
		result = left_blank_padding(flag, len, &c);
	else if (!flag.minus && flag.zero)
		result = left_zero_padding(&c, len);
	else
		result = right_blank_padding(flag, len, &c);
	return (result);
}

int	percent_handle(t_flag flag)
{
	char	*result;
	int		len;

	len = 0;
	if (flag.width == 0)
	{
		write(1, "%", 1);
		g_count++;
	}
	else
	{
		len += flag.width;
		result = percent_padding(flag, len);
		if (!result)
			return (0);
		print_str(flag, result, ft_strlen(result));
	}
	return (1);
}
