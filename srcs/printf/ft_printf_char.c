/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:21:07 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/16 18:21:07 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_char(char c, t_flags flags)
{
	int	printed_len;

	printed_len = 0;
	if (flags.minus)
		printed_len += ft_print_char(c);
	printed_len += ft_print_width(flags.width, 1, 0);
	if (!flags.minus)
		printed_len += ft_print_char(c);
	return (printed_len);
}
