/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:48:25 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/13 11:57:46 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long int n, int is_upper)
{
	char	*base;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n < 16)
		return (ft_print_char(base[n]));
	else
		return (ft_print_hex(n / 16, is_upper)
			+ ft_print_hex(n % 16, is_upper));
}

static int	ft_printf_hex_minus_dot(long int n, t_flags flags, int is_upper)
{
	int	printed_len;
	int	printed;

	printed = 0;
	printed_len = 0;
	if (flags.dot >= 0 && flags.dot > ft_hex_size(n)
		&& flags.dot >= flags.width)
		printed_len += ft_printf_pre(ft_hex_size(n), flags);
	else
	{
		printed = 1;
		if (flags.width > flags.dot)
		{
			printed_len += ft_print_width(flags.dot, ft_hex_size(n), 1);
			printed_len += ft_print_hex(n, is_upper);
			if (printed_len != flags.width)
				printed_len += ft_print_width(flags.width, printed_len, 0);
		}
		else
			printed_len += ft_print_hex(n, is_upper);
	}
	if (!printed)
		printed_len += ft_print_hex(n, is_upper);
	return (printed_len);
}

static int	ft_printf_hex_zero_dot(long int n, t_flags flags, int is_upper)
{
	int	printed_len;

	printed_len = 0;
	if (flags.width > flags.dot && ft_hex_size(n) > flags.dot)
		printed_len += ft_print_width(flags.width, ft_hex_size(n), 0);
	else if (flags.width > flags.dot)
	{
		printed_len += ft_print_width(flags.width, flags.dot, 0);
		printed_len += ft_print_width(flags.dot, ft_hex_size(n), 1);
	}
	else if (flags.dot >= flags.width)
		printed_len += ft_printf_pre(ft_hex_size(n), flags);
	else
		printed_len += ft_print_width(flags.width, ft_hex_size(n), flags.zero);
	printed_len += ft_print_hex(n, is_upper);
	return (printed_len);
}

int	ft_printf_hex(unsigned int n, int is_upper, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (!n && !flags.dot)
		return (printed_len + ft_print_width(flags.width, 0, 0));
	if (flags.minus && flags.dot >= 0)
		return (ft_printf_hex_minus_dot(n, flags, is_upper));
	else if (flags.minus)
		printed_len += ft_print_hex(n, is_upper);
	else if (flags.zero && flags.dot >= 0)
		return (ft_printf_hex_zero_dot(n, flags, is_upper));
	if (flags.sharp)
		flags.width -= 2;
	if (flags.dot >= 0 && flags.dot > ft_hex_size(n))
		printed_len += ft_printf_pre(ft_hex_size(n), flags);
	else
		printed_len += ft_print_width(flags.width, ft_hex_size(n), flags.zero);
	if (flags.sharp && n)
		printed_len += ft_print_str("0") + ft_print_char(flags.type);
	if (!n && !flags.dot)
		return (printed_len);
	if (!flags.minus)
		printed_len += ft_print_hex(n, is_upper);
	return (printed_len);
}
