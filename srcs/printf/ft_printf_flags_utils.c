/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:28:48 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/16 18:28:48 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isflagtype(int c)
{
	if (ft_strchr("-0.# +", c))
		return (1);
	return (0);
}

int	ft_istype(int c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isflagtype(c));
}
