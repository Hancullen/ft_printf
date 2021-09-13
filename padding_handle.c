/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:56:04 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/23 16:45:20 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*left_blank_padding(t_flag flag, int len, char *str)
{
	int		i;
	char	*result;

	result = ft_calloc(len + 1, 1);
	i = 0;
	if ((flag.type == '%') || (flag.type == 'c'))
	{
		while (i < len - 1)
			result[i++] = ' ';
		result[i++] = *str;
	}
	else
	{
		while (i < (int)(flag.width - ft_strlen(str)))
			result[i++] = ' ';
		while (*str)
			result[i++] = *str++;
	}
	return (result);
}

char	*left_zero_padding(char *str, int len)
{
	char	*result;
	int		i;

	result = ft_calloc(len + 1, 1);
	i = 0;
	while (i < len - 1)
		result[i++] = '0';
	result[i] = *str;
	return (result);
}

char	*right_blank_padding(t_flag flag, int len, char *str)
{
	char	*result;
	int		i;

	result = ft_calloc(len + 1, 1);
	i = 0;
	if ((flag.type == '%') || (flag.type == 'c'))
	{
		result[i++] = *str;
		while (i < len)
			result[i++] = ' ';
	}
	else
	{
		while (*str)
			result[i++] = *str++;
		while (i < len)
			result[i++] = ' ';
	}
	return (result);
}
