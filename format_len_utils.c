/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_len_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:57:05 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:57:07 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_arg_length(t_format *format, va_list ap)
{
	va_list ap_copy;

	va_copy(ap_copy, ap);
	if (format->type == 'c' || format->type == '%')
		format->arg_length = 1;
	else if (format->type == 's')
		format->arg_length = ft_strlen(va_arg(ap_copy, char *));
	else if (format->type == 'd' || format->type == 'i')
		format->arg_length = ft_numlen(va_arg(ap_copy, int), 10);
	else if (format->type == 'u')
		format->arg_length = ft_numlen(va_arg(ap_copy, unsigned int), 10);
	else if (format->type == 'x' || format->type == 'X')
		format->arg_length = ft_numlen(va_arg(ap_copy, unsigned int), 16);
	else if (format->type == 'p')
		format->arg_length = ft_numlen_p(va_arg(ap_copy, unsigned long), 16);
}

int		ft_numlen(long number, int base)
{
	int number_len;

	number_len = 1;
	while (number /= base)
		number_len++;
	return (number_len);
}

int		ft_numlen_p(unsigned long number, int base)
{
	int number_len;

	number_len = 1;
	while (number /= base)
		number_len++;
	return (number_len);
}
