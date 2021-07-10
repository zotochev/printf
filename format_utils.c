/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:57:30 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:57:31 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		arg_length_correction(t_format *format, va_list ap)
{
	va_list	ap_copy;
	int		neg_check;

	va_copy(ap_copy, ap);
	neg_check = va_arg(ap_copy, int);
	if ((format->type == 'd' || format->type == 'i') && neg_check < 0)
		format->negative = 1;
	if ((ft_strchr("pdiuxX", format->type)))
	{
		if (format->arg_length < format->precision)
			format->arg_length = format->precision;
		if (neg_check == 0 && format->precision == 0)
			format->arg_length = 0;
	}
	if ((ft_strchr("s", format->type)))
	{
		if ((format->arg_length > format->precision) && format->precision >= 0)
			format->arg_length = format->precision;
	}
}

t_format	new_format_object(void)
{
	t_format new;

	new.valid = 1;
	new.flag_minus = 0;
	new.flag_null = 0;
	new.width = 0;
	new.precision = -1;
	new.type = '\0';
	new.format_len = 0;
	new.arg_length = 0;
	new.negative = 0;
	return (new);
}

void		print_char(char c, int num)
{
	while (num-- > 0)
		ft_putchar_fd(c, 1);
}

void		format_print_out(t_format *fmt)
{
	char	fill_sym;

	if ((!fmt->flag_minus && fmt->flag_null)
		&& (fmt->precision < 0 || ft_strchr("s%", fmt->type)))
		fill_sym = '0';
	else
		fill_sym = ' ';
	if (fmt->negative && fmt->precision < 0 && fmt->flag_null)
		ft_putchar_fd('-', 1);
	if (!fmt->flag_minus)
	{
		if ((fmt->width > fmt->arg_length) && fmt->type == 'p')
			print_char(fill_sym, fmt->width - fmt->arg_length - 2);
		if ((fmt->width > fmt->arg_length) && fmt->type != 'p')
			print_char(fill_sym, fmt->width - fmt->arg_length - fmt->negative);
	}
	if (fmt->negative && (fmt->precision >= 0 || !fmt->flag_null))
		ft_putchar_fd('-', 1);
}

void		format_print_out_after(t_format *fmt)
{
	char	fill_sym;

	fill_sym = ' ';
	if (fmt->type && fmt->flag_minus)
	{
		if ((fmt->width > fmt->arg_length) && fmt->type == 'p')
			print_char(fill_sym, fmt->width - fmt->arg_length - 2);
		if ((fmt->width > fmt->arg_length) && fmt->type != 'p')
			print_char(fill_sym, fmt->width - fmt->arg_length - fmt->negative);
	}
}
