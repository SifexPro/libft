/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:30:36 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/09 17:40:40 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		res = (char *)malloc(sizeof(char));
	else if (start + len > ft_strlen(s))
		res = (char *)malloc(sizeof(char) * (ft_strlen(&s[start]) + 1));
	else if (len < ft_strlen(s))
		res = (char *)malloc(sizeof(char) * (len + 1));
	else
		res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s || !res)
		return (NULL);
	while (start < ft_strlen(s) && s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
