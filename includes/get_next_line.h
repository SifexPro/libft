/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:34:41 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/18 19:34:41 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list	*stash_new(char *content, int size);
void	stash_add_back(t_list **lst, t_list *new);
void	stash_clear(t_list **lst, int count);
void	create_line(t_list *stash, char **line);
int		has_newline(char *str, int return_len);

char	*get_next_line(int fd);

#endif