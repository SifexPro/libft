/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:20:36 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/09 17:45:31 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		if ((*lst)->content)
			del((*lst)->content);
		if (*lst)
			free(*lst);
		(*lst) = tmp;
	}
}
