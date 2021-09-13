/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_padding_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:30:12 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/18 14:55:48 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_decision(t_flag *flag, int *total, int *len)
{
	*total = *len;
	if (flag->precision > *total)
		*total = flag->precision;
	else
		flag->precision = 0;
	if (flag->width > *total)
		*total = flag->width;
	else
		flag->width = 0;
}

char	*left_blank_num(t_flag *flag, int len, char *str)
{
	char	*result;
	int		total;
	int		i;

	len_decision(flag, &total, &len);
	result = ft_calloc(total + flag->neg_num + 1, 1);
	i = 0;
	if (flag->precision > len)
		while (i < total - flag->precision)
			result[i++] = ' ';
	else if (flag->width >= len)
	{
		flag->width = len;
		while (i < (total - flag->width - flag->precision - flag->neg_num))
			result[i++] = ' ';
	}
	if (flag->neg_num)
		result[i++] = '-';
	while (i < total - len)
		result[i++] = '0';
	while (len)
		result[i++] = str[--len];
	return (result);
}

char	*right_blank_num(t_flag flag, int len, char *str)
{
	char	*result;
	int		total;
	int		i;

	len_decision(&flag, &total, &len);
	result = ft_calloc(total + flag.neg_num + 1, 1);
	i = 0;
	if (flag.neg_num)
		result[i++] = '-';
	while (i < flag.precision - len)
		result[i++] = '0';
	while (len)
		result[i++] = str[--len];
	while (i < total)
		result[i++] = ' ';
	return (result);
}

char	*left_zero_num(t_flag flag, int len, char *str)
{
	char	*result;
	int		total;
	int		i;

	total = len;
	if (flag.width > total)
		total = flag.width;
	result = ft_calloc(total + flag.neg_num + 1, 1);
	i = 0;
	if (flag.neg_num)
		result[i++] = '-';
	while (i < total - len)
		result[i++] = '0';
	while (len)
		result[i++] = str[--len];
	return (result);
}
