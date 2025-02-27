/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:26:45 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/13 15:16:56 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

// Flags
typedef struct s_flags
{
	int	type;
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	sign;
	int	space;
	int	width;
}		t_flags;

int		ft_istype(int c);
int		ft_isflag(int c);
t_flags	ft_flags_init(void);
int		ft_print_width(int width, int size, int is_zero);
int		ft_flags_precision(const char *str, int i, t_flags *flags);
int		ft_printf_pre(int size, t_flags flags);

// Size
int		ft_hex_size(unsigned long long n);
int		ft_int_size(long int n);
int		ft_uint_size(unsigned long n);

// Utils
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_hex(unsigned long int n, int is_upper);

// ft_printf
int		ft_printf(const char *str, ...);
int		ft_printf_type(char type, va_list var_list, t_flags flags);
int		ft_printf_char(char c, t_flags flags);
int		ft_printf_str(char *str, t_flags flags);
int		ft_printf_ptr(unsigned long int n, t_flags flags);
int		ft_printf_nbr(long int n, t_flags flags, int printed_len);
int		ft_printf_unsigned(unsigned int n, t_flags flags);
int		ft_printf_hex(unsigned int n, int is_upper, t_flags flags);

#endif