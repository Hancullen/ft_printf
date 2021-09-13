/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_padding_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:04:37 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/18 15:10:33 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*left_blank_str(t_flag flag, char *str, int len)
{
	char	*s;
	int		i;
	int		total;

	i = 0;
	total = len;
	if (flag.width > total)
		total = flag.width;
	s = ft_calloc(total + 1, 1);
	while (i < total - len)
		s[i++] = ' ';
	while (i < total && str[len - 1])
		s[i++] = str[--len];
	return (s);
}

char	*right_blank_str(t_flag flag, char *str, int len)
{
	char	*s;
	int		i;
	int		total;

	i = 0;
	total = len;
	if (flag.width > len)
		total = flag.width;
	s = ft_calloc(total + 1, 1);
	while (i < len && str[len - i - 1])
	{
		s[i] = str[len - i - 1];
		i++;
	}
	while (i < total)
		s[i++] = ' ';
	return (s);
}
