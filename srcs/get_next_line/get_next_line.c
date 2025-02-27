/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:34:39 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/18 19:34:39 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	j = 0;
	if (!stash)
		return ;
	create_line(stash, line);
	if (!line)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			(*line)[j++] = stash->content[i];
			if (stash->content[i] == '\n')
				break ;
			i++;
		}
		if (stash->content[i] == '\n')
			break ;
		stash = stash->next;
	}
	(*line)[j] = 0;
}

void	read_to_stash(int fd, t_list **stash)
{
	char	*buf;
	int		pos;

	pos = 1;
	while (pos != 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		pos = read(fd, buf, BUFFER_SIZE);
		if (pos == -1 || (!*stash && !pos))
		{
			free(buf);
			return ;
		}
		buf[pos] = 0;
		if (has_newline(buf, 1) > 0)
			stash_add_back(stash, stash_new(buf, pos));
		if (has_newline(buf, 0))
		{
			free(buf);
			break ;
		}
		free(buf);
	}
}

static int	stash_clean_nl(t_list *tmp, t_list **new, int i)
{
	if (tmp->content[i] == '\n')
	{
		if (tmp->content[i + 1])
		{
			(*new) = stash_new(&tmp->content[i + 1],
					has_newline(&tmp->content[i + 1], 1));
			(*new)->next = tmp->next;
		}
		else if (tmp->next)
		{
			(*new) = tmp->next;
			(*new)->next = tmp->next->next;
		}
		return (1);
	}
	return (0);
}

void	stash_clean(t_list **stash)
{
	int		i;
	int		count;
	t_list	*new;
	t_list	*tmp;

	count = 0;
	new = NULL;
	tmp = *stash;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (stash_clean_nl(tmp, &new, i))
				break ;
			i++;
		}
		count++;
		if (tmp->content[i] == '\n')
			break ;
		tmp = tmp->next;
	}
	stash_clear(stash, count);
	*stash = new;
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash[1025];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) == -1)
		return (NULL);
	read_to_stash(fd, &stash[fd]);
	if (!stash[fd])
		return (NULL);
	get_line(stash[fd], &line);
	if (stash[fd])
		stash_clean(&stash[fd]);
	if (!line || !line[0])
	{
		stash_clear(&stash[fd], -1);
		stash[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
