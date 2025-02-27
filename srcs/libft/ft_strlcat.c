/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:46:14 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/09 14:59:27 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	if ((!src && !dst) || ((!src || !dst) && !size))
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (!size)
		return (src_len);
	else if (size <= dst_len)
		return (size + src_len);
	while (size && (--size - dst_len) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
