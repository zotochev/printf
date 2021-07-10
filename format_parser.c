/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:57:17 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:57:19 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(const char *string, t_format *format)
{
	int count;

	count = 0;
	while (*string && ft_strchr(FLAGS, *string))
	{
		if (*string == '-')
			format->flag_minus = 1;
		if (*string == '0')
			format->flag_null = 1;
		string++;
		count++;
	}
	format->format_len += count;
}

void	get_width(const char *string, t_format *format, va_list ap)
{
	int count;

	count = 0;
	if (*string >= '0' && *string <= '9')
		format->width = ft_atoi(string);
	else if (*string == '*')
		format->width = va_arg(ap, int);
	while (*string && ((*string >= '0' && *string <= '9') || *string == '*'))
	{
		count++;
		string++;
	}
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width = -format->width;
	}
	format->format_len += count;
}

void	get_precision(const char *string, t_format *format, va_list ap)
{
	int count;

	count = 0;
	if (*string && *string == '.')
	{
		string++;
		count++;
		if (*string == '*')
			format->precision = va_arg(ap, int);
		else
			format->precision = ft_atoi(string);
		while (*string && ((*string >= '0' && *string <= '9')
				|| *string == '*'))
		{
			count++;
			string++;
		}
	}
	format->format_len += count;
}

void	get_type(const char *string, t_format *format)
{
	if (*string && ft_strchr(TYPES, *string))
	{
		format->type = *string;
		format->format_len += 1;
	}
}

void	format_parser(const char *string, t_format *format, va_list ap)
{
	get_flag(string + format->format_len, format);
	get_width(string + format->format_len, format, ap);
	get_precision(string + format->format_len, format, ap);
	get_type(string + format->format_len, format);
	get_arg_length(format, ap);
	arg_length_correction(format, ap);
}
