/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:57:42 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:57:44 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_processor(const char *string, t_format *format, va_list ap)
{
	*format = new_format_object();
	if (*string)
		format_parser(string, format, ap);
	format_print_out(format);
	arg_print_out(format, ap);
	format_print_out_after(format);
}

int		ft_printf(const char *string, ...)
{
	va_list		ap;
	t_format	format;

	if (!string)
		return (0);
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
		{
			format_processor(++string, &format, ap);
			if (*string)
				string += format.format_len;
		}
		if (*string && *string != '%')
		{
			ft_putchar_fd(*string, 1);
			string++;
		}
	}
	va_end(ap);
	return (ft_putchar_fd('\0', -1));
}
