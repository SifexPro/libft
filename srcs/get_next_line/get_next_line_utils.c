/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:59:47 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/20 12:59:47 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*stash_new(char *content, int size)
{
	int		i;
	t_list	*res;

	i = 0;
	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = (char *)malloc(sizeof(char) * (size + 1));
	if (!res->content)
		return (NULL);
	while (i < size)
	{
		res->content[i] = content[i];
		i++;
	}
	res->content[i] = 0;
	res->next = NULL;
	return (res);
}

void	stash_add_back(t_list **lst, t_list *new)
{
	t_list	*lst_start;

	lst_start = *lst;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	(*lst) = lst_start;
}

void	stash_clear(t_list **lst, int count)
{
	int		i;
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		if (count == -1 || i++ < count)
		{
			if ((*lst)->content)
				free((*lst)->content);
			if (*lst)
				free(*lst);
		}
		(*lst) = tmp;
	}
}

void	create_line(t_list *stash, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			len++;
			if (stash->content[i] == '\n')
				break ;
			i++;
		}
		if (stash->content[i] == '\n')
			break ;
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	has_newline(char *str, int return_len)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' && !return_len)
			return (1 + i);
		i++;
	}
	if (return_len)
		return (i);
	return (0);
}
