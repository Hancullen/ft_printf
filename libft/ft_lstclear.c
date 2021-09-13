/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:46:41 by linguyen          #+#    #+#             */
/*   Updated: 2021/05/29 14:39:22 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev_node;

	if (!del)
		return ;
	while (*lst != NULL)
	{
		prev_node = *lst;
		*lst = (*lst)->next;
		del(prev_node->content);
		free(prev_node);
	}
	*lst = NULL;
}
