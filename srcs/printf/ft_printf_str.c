/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:21:37 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/16 18:21:37 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf_str(char *str, t_flags flags)
{
	int	first_str_len;
	int	str_len;
	int	printed_len;

	printed_len = 0;
	if (!str && flags.dot >= 0 && flags.dot < 6)
		str = "";
	else if (!str)
		str = "(null)";
	first_str_len = (int)ft_strlen(str);
	if (flags.dot >= 0 && flags.dot < first_str_len)
		str = ft_substr(str, 0, flags.dot);
	str_len = (int)ft_strlen(str);
	if (flags.minus)
		printed_len += ft_print_str(str);
	printed_len += ft_print_width(flags.width, str_len, 0);
	if (!flags.minus)
		printed_len += ft_print_str(str);
	if (flags.dot >= 0 && flags.dot < first_str_len)
		free(str);
	return (printed_len);
}
