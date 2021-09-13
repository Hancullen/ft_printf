/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:23:43 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/31 20:48:28 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	joined_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined_str == NULL)
		return (NULL);
	joined_str = ft_strcpy(joined_str, s1);
	joined_str = ft_strcat(joined_str, s2);
	return (joined_str);
}
