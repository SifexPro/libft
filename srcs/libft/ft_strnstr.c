/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:34:59 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/09 14:59:43 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !len)
		return (NULL);
	if (!s2[0])
		return ((char *)(s1));
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s1[i + j] == s2[j] && i + j < len)
		{
			if (!s2[j + 1])
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
