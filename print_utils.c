/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:58:13 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:58:15 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_precision(char *s, t_format *format)
{
	int precision;
	int fd;

	precision = format->precision;
	if (!s)
	{
		ft_putstr_precision("(null)", format);
		return ;
	}
	if (format->type)
		fd = 1;
	else
		fd = 2;
	while (*s && precision--)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

unsigned long	exp_of_ten(int exp, int base)
{
	long result;

	result = 1;
	while (exp--)
		result *= base;
	return (result);
}

void			put_number_iter(long number, int base, t_format *format)
{
	int				number_len;
	unsigned long	delimiter;
	long			temp;

	number_len = ft_numlen(number, base);
	number = (number > 0) ? number : -number;
	delimiter = exp_of_ten(number_len, base);
	if (number == 0 && format->precision == 0)
		return ;
	print_char('0', format->precision - number_len);
	while (number_len-- > 0)
	{
		temp = (((number / (delimiter /= base)) % base));
		if (temp < 10)
			ft_putchar_fd((temp + '0'), 1);
		else
			ft_putchar_fd((temp + format->type - 33), 1);
	}
}

void			print_unsigned_number_iter(unsigned long number,
									int base, t_format *format)
{
	int				number_len;
	unsigned long	delimiter;
	unsigned long	temp;

	number_len = format->arg_length;
	delimiter = exp_of_ten(number_len, base);
	ft_putstr_fd("0x", 1);
	print_char('0', format->precision - format->arg_length);
	while (number_len-- > 0)
	{
		temp = ((number / (delimiter /= base)) % base);
		if (temp < 10)
			ft_putchar_fd((temp + '0'), 1);
		else
			ft_putchar_fd((temp + 'x' - 33), 1);
	}
}
