/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:08:36 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/13 15:51:28 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_ptr_null(t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (flags.minus)
		printed_len += ft_print_str("(nil)");
	printed_len += ft_print_width(flags.width, 5, 0);
	if (!flags.minus)
		printed_len += ft_print_str("(nil)");
	return (printed_len);
}

int	ft_printf_ptr(unsigned long int n, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (n <= 0)
		return (ft_printf_ptr_null(flags));
	if (flags.zero)
		printed_len += ft_print_str("0x");
	else if (flags.minus)
		printed_len += ft_print_str("0x") + ft_print_hex(n, 0);
	else if (flags.sign || flags.space)
		flags.width--;
	printed_len += ft_print_width(flags.width, ft_hex_size(n) + 2, flags.zero);
	if (flags.sign)
		printed_len += ft_print_char('+');
	else if (flags.space)
		printed_len += ft_print_char(' ');
	if (flags.zero)
		printed_len += ft_print_hex(n, 0);
	else if (!flags.minus)
		printed_len += ft_print_str("0x") + ft_print_hex(n, 0);
	return (printed_len);
}
