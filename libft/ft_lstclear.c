/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:15:15 by chorst            #+#    #+#             */
/*   Updated: 2023/11/24 10:18:07 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*deletednode;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		deletednode = *lst;
		del(deletednode->content);
		*lst = deletednode->next;
		free(deletednode);
	}
	*lst = NULL;
}
