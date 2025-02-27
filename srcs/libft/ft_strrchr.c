/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:16:36 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/08 12:09:18 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res_i;

	i = 0;
	res_i = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			res_i = i;
		i++;
	}
	if (s[i] == (unsigned char)c)
		res_i = i;
	if (res_i != -1)
		return ((char *)s + res_i);
	return (NULL);
}
