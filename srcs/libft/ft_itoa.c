/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:58:29 by Sifex             #+#    #+#             */
/*   Updated: 2023/10/15 19:58:29 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static size_t	size_of_nb(int n)
{
	size_t	res;

	res = 0;
	if (n == 0)
		res++;
	else if (n == -2147483648)
		res = 11;
	else if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	is_neg;
	char	*res;

	i = 0;
	is_neg = (n < 0);
	res = (char *)malloc(sizeof(char) * (size_of_nb(n) + 1));
	if (!res)
		return (NULL);
	if (n == 0)
		res[i++] = '0';
	while (n != 0)
	{
		res[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}
