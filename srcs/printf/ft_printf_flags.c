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

t_flags	ft_flags_init(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.sharp = 0;
	flags.sign = 0;
	flags.space = 0;
	flags.width = 0;
	return (flags);
}

int	ft_print_width(int width, int size, int is_zero)
{
	int	printed_len;

	printed_len = 0;
	while (width - size > 0)
	{
		if (is_zero)
			printed_len += ft_print_char('0');
		else
			printed_len += ft_print_char(' ');
		width--;
	}
	return (printed_len);
}

int	ft_flags_precision(const char *str, int i, t_flags *flags)
{
	i++;
	flags->dot = 0;
	while (ft_isdigit(str[i]))
	{
		flags->dot = (flags->dot * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	ft_printf_pre(int size, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (flags.width > size)
		printed_len += ft_print_width(flags.width, flags.dot, 0);
	printed_len += ft_print_width(flags.dot, size, 1);
	return (printed_len);
}
