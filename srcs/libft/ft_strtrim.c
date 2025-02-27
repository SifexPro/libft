/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:01:53 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/09 17:41:47 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (!is_in_set(s1[i], set))
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	len;
	int		start;
	int		end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = find_start(s1, set);
	end = find_end(s1, set);
	len = end - start + 1;
	if (start > end || ft_strlen(s1) == 0 || start == -1 || end == -1)
		len = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < (int)len)
	{
		res[i] = s1[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
