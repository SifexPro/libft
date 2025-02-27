/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:12:02 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/09 17:42:01 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static size_t	nword_len(char const *s, char c, size_t i)
{
	size_t	res;

	res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			break ;
		}
		i++;
	}
	return (res);
}

static char	*declare_entry(char *entry, size_t size)
{
	entry = (char *)malloc(sizeof(char) * size);
	if (!entry)
		return (NULL);
	(*entry) = 0;
	return (entry);
}

static char	**ft_split_fill(char const *s, char c, char **res, char *entry)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
			entry[j++] = s[i];
		if ((s[i] == c || !s[i + 1]) && j > (size_t)0)
		{
			entry[j] = '\0';
			res[k++] = entry;
			if (nword_len(s, c, i) != 0 && k != count_words(s, c))
				entry = declare_entry(entry, nword_len(s, c, i) + 1);
			if (!entry)
				return (NULL);
			j = 0;
		}
		i++;
	}
	res[k] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*entry;

	if (!s)
		return (NULL);
	entry = NULL;
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	entry = declare_entry(entry, nword_len(s, c, 0) + 1);
	if (!s || !res || !entry)
		return (NULL);
	(*res) = 0;
	if (nword_len(s, c, 0) == 0)
		free(entry);
	res = ft_split_fill(s, c, res, entry);
	return (res);
}
