/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:16:37 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/13 15:16:50 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(char type, va_list var_list, t_flags flags)
{
	if (type == 'c')
		return (ft_printf_char(va_arg(var_list, int), flags));
	else if (type == 's')
		return (ft_printf_str(va_arg(var_list, char *), flags));
	else if (type == 'p')
		return (ft_printf_ptr(va_arg(var_list, unsigned long long), flags));
	else if (type == 'd' || type == 'i')
		return (ft_printf_nbr((long int)va_arg(var_list, int), flags, 0));
	else if (type == 'u')
		return (ft_printf_unsigned(va_arg(var_list, unsigned int), flags));
	else if (type == 'x')
		return (ft_printf_hex(va_arg(var_list, unsigned int), 0, flags));
	else if (type == 'X')
		return (ft_printf_hex(va_arg(var_list, unsigned int), 1, flags));
	else if (type == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_printf_flags(const char *str, int i, int saved_i, t_flags *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			flags->minus = 1;
		if (str[i] == '0' && !flags->width)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flags_precision(str, i, flags);
		if (str[i] == '#')
			flags->sharp = 1;
		if (str[i] == '+')
			flags->sign = 1;
		if (str[i] == ' ' && !flags->sign)
			flags->space = 1;
		if (ft_isdigit(str[i]) && flags->dot == -1)
			flags->width = (flags->width * 10) + (str[i] - '0');
		if (ft_istype(str[i]))
		{
			flags->type = str[i];
			return (i);
		}
	}
	return (saved_i);
}

static int	ft_printf_parser(const char *str, int *i, va_list var_list)
{
	int		printed_len;
	t_flags	flags;

	printed_len = 0;
	flags = ft_flags_init();
	if (str[*i] == '%' && str[*i + 1])
	{
		*i = ft_printf_flags(str, *i, *i, &flags);
		if (flags.type > 0 && ft_istype(str[*i]))
			printed_len += ft_printf_type(str[*i], var_list, flags);
		else if (str[*i])
			printed_len += ft_print_char(str[*i]);
	}
	else
		printed_len += ft_print_char(str[*i]);
	return (printed_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed_len;
	va_list	var_list;

	if (!str || !str[0])
		return (0);
	i = 0;
	printed_len = 0;
	va_start(var_list, str);
	while (str[i])
	{
		printed_len += ft_printf_parser(str, &i, var_list);
		i++;
	}
	va_end(var_list);
	return (printed_len);
}
