/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:08:15 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/08 14:14:43 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_start;

	lst_start = *lst;
	if (!ft_lstlast(*lst))
	{
		(*lst) = new;
		return ;
	}
	*lst = ft_lstlast(*lst);
	(*lst)->next = new;
	(*lst) = lst_start;
}
