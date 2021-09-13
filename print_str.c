/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:36:59 by linguyen          #+#    #+#             */
/*   Updated: 2021/08/04 22:54:16 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_flag flag, char *str, int len)
{
	char	c;
	int		i;

	i = 0;
	if (flag.type == 'X')
	{
		while (str[i])
		{
			c = ft_toupper(str[i]);
			write(1, &c, 1);
			i++;
			g_count++;
		}
	}
	else
	{
		while (i < len)
		{
			write(1, &str[i], 1);
			i++;
			g_count++;
		}
	}
	free(str);
}
