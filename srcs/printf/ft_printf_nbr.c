/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:44 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/16 18:24:44 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr(long int n)
{
	if (n < 0)
		return (ft_print_char('-') + ft_print_nbr(n * -1));
	else if (n < 10)
		return (ft_print_char(n + '0'));
	else
		return (ft_print_nbr(n / 10) + ft_print_nbr(n % 10));
}

static int	ft_printf_nbr_neg(long int *n, t_flags flags, int *printed)
{
	int	printed_len;

	printed_len = 0;
	printed_len += ft_print_char('-');
	if (flags.minus && flags.dot >= 0 && flags.width > flags.dot)
	{
		*printed = 1;
		printed_len += ft_print_width(flags.dot, ft_int_size(-(*n)), 1);
		printed_len += ft_print_nbr(-(*n));
		printed_len += ft_print_width(flags.width - 1, flags.dot, 0);
		return (printed_len);
	}
	else if (flags.dot >= 0)
		printed_len += ft_print_width(flags.dot, ft_int_size(-(*n)), 1);
	else
		printed_len += ft_print_width(flags.width, ft_int_size(*n), flags.zero);
	*n *= -1;
	return (printed_len);
}

static int	ft_printf_nbr_minus_dot(long int n, t_flags flags)
{
	int	printed_len;
	int	printed;

	printed = 0;
	printed_len = 0;
	if (n < 0 && flags.dot >= 0)
		printed_len += ft_printf_nbr_neg(&n, flags, &printed);
	else if (flags.dot > ft_int_size(n) && flags.dot >= flags.width)
		printed_len += ft_printf_pre(ft_int_size(n), flags);
	else if (flags.minus && n >= 0)
	{
		printed = 1;
		if (flags.width > flags.dot)
			printed_len += ft_print_width(flags.dot, ft_int_size(n), 1);
		printed_len += ft_print_nbr(n);
		if (printed_len != flags.width)
			printed_len += ft_print_width(flags.width, printed_len, 0);
	}
	else
		printed_len += ft_print_width(flags.width, ft_int_size(n), flags.zero);
	if (!printed)
		printed_len += ft_print_nbr(n);
	return (printed_len);
}

static int	ft_printf_nbr_zero_dot(long int n, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (flags.width > flags.dot && n < 0 && flags.dot > ft_int_size(n))
		printed_len += ft_print_width(flags.width - 1, flags.dot, 0);
	else if (flags.width > flags.dot && n < 0)
		printed_len += ft_print_width(flags.width, ft_int_size(n), 0);
	else if (flags.width > flags.dot && n >= 0 && ft_int_size(n) > flags.dot)
		printed_len += ft_print_width(flags.width, ft_int_size(n), 0);
	else if (flags.width > flags.dot && n >= 0)
	{
		printed_len += ft_print_width(flags.width, flags.dot, 0);
		printed_len += ft_print_width(flags.dot, ft_int_size(n), 1);
	}
	else if (flags.dot >= flags.width && n >= 0)
		printed_len += ft_printf_pre(ft_int_size(n), flags);
	else if (n > 0)
		printed_len += ft_print_width(flags.width, ft_int_size(n), flags.zero);
	if (n < 0)
		printed_len += ft_printf_nbr_neg(&n, flags, 0);
	printed_len += ft_print_nbr(n);
	return (printed_len);
}

int	ft_printf_nbr(long int n, t_flags flags, int printed_len)
{
	if (!n && !flags.dot)
		return (printed_len + ft_print_width(flags.width, 0, 0));
	if (flags.minus && flags.dot >= 0)
		return (ft_printf_nbr_minus_dot(n, flags));
	else if (flags.minus)
		printed_len += ft_print_nbr(n);
	else if (flags.zero && flags.dot >= 0)
		return (ft_printf_nbr_zero_dot(n, flags));
	else if (flags.sign || flags.space)
		flags.width--;
	if (n < 0 && (flags.zero || flags.dot >= 0))
		printed_len += ft_printf_nbr_neg(&n, flags, 0);
	else if (flags.dot >= 0 && flags.dot > ft_int_size(n))
		printed_len += ft_printf_pre(ft_int_size(n), flags);
	else
		printed_len += ft_print_width(flags.width, ft_int_size(n), flags.zero);
	if (flags.sign && n >= 0)
		printed_len += ft_print_char('+');
	else if (flags.space && n >= 0)
		printed_len += ft_print_char(' ');
	if (!flags.minus)
		printed_len += ft_print_nbr(n);
	return (printed_len);
}
