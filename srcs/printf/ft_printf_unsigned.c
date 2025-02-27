/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:48:25 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/11 19:48:25 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_unsigned(unsigned int n)
{
	if (n < 10)
		return (ft_print_char(n + '0'));
	else
		return (ft_print_unsigned(n / 10) + ft_print_unsigned(n % 10));
}

static int	ft_printf_uint_minus_dot(long int n, t_flags flags)
{
	int	printed_len;
	int	printed;

	printed = 0;
	printed_len = 0;
	if (flags.dot > ft_uint_size(n) && flags.dot >= flags.width)
		printed_len += ft_printf_pre(ft_uint_size(n), flags);
	else
	{
		printed = 1;
		if (flags.width > flags.dot)
		{
			printed_len += ft_print_width(flags.dot, ft_uint_size(n), 1);
			printed_len += ft_print_unsigned(n);
			if (printed_len != flags.width)
				printed_len += ft_print_width(flags.width, printed_len, 0);
		}
		else
			printed_len += ft_print_unsigned(n);
	}
	if (!printed)
		printed_len += ft_print_unsigned(n);
	return (printed_len);
}

static int	ft_printf_uint_zero_dot(long int n, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (flags.width > flags.dot && ft_uint_size(n) > flags.dot)
		printed_len += ft_print_width(flags.width, ft_uint_size(n), 0);
	else if (flags.width > flags.dot)
	{
		printed_len += ft_print_width(flags.width, flags.dot, 0);
		printed_len += ft_print_width(flags.dot, ft_uint_size(n), 1);
	}
	else if (flags.dot >= flags.width)
		printed_len += ft_printf_pre(ft_uint_size(n), flags);
	else
		printed_len += ft_print_width(flags.width, ft_uint_size(n), flags.zero);
	printed_len += ft_print_unsigned(n);
	return (printed_len);
}

int	ft_printf_unsigned(unsigned int n, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (!n && !flags.dot)
		return (printed_len + ft_print_width(flags.width, 0, 0));
	if (flags.minus && flags.dot >= 0)
		return (ft_printf_uint_minus_dot(n, flags));
	else if (flags.minus)
		printed_len += ft_print_unsigned(n);
	else if (flags.zero && flags.dot >= 0)
		return (ft_printf_uint_zero_dot(n, flags));
	if (flags.dot >= 0 && flags.dot > ft_uint_size(n))
		printed_len += ft_printf_pre(ft_uint_size(n), flags);
	else
		printed_len += ft_print_width(flags.width, ft_uint_size(n), flags.zero);
	if (!n && !flags.dot)
		return (printed_len);
	if (!flags.minus)
		printed_len += ft_print_unsigned(n);
	return (printed_len);
}
