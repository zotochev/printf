/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:56:36 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:56:39 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

# define FLAGS "-0"
# define TYPES "cspdiuxX%"

/*
** DEBAG
*/
# include <stdio.h>

/*
** END DEBAG
*/

typedef struct	s_format
{
	int		valid;
	int		flag_minus;
	int		flag_null;
	int		width;
	int		precision;
	char	type;
	int		format_len;
	int		arg_length;
	int		negative;
}				t_format;

int				ft_printf(const char *string, ...);
void			format_processor(const char *string, t_format *format,
				va_list ap);
/*
**	print_processor.c
*/
void			arg_print_out(t_format *format, va_list ap);

/*
**	print_utils.c
*/
void			ft_putstr_precision(char *s, t_format *format);
unsigned long	exp_of_ten(int exp, int base);
void			put_number_iter(long number, int base, t_format *format);
void			print_unsigned_number_iter(unsigned long number, int base,
				t_format *format);

/*
**	format_parser.c
*/
void			get_flag(const char *string, t_format *format);
void			get_width(const char *string, t_format *format, va_list ap);
void			get_precision(const char *string, t_format *format, va_list ap);
void			get_type(const char *string, t_format *format);
void			format_parser(const char *string, t_format *format, va_list ap);

/*
**	format_utils.c
*/
t_format		new_format_object(void);
void			arg_length_correction(t_format *format, va_list ap);
void			print_char(char c, int num);
void			format_print_out(t_format *fmt);
void			format_print_out_after(t_format *fmt);

/*
**	format_len_utils.c
*/
void			get_arg_length(t_format *format, va_list ap);
int				ft_numlen(long number, int base);
int				ft_numlen_p(unsigned long number, int base);

/*
**	print_string_utils.c
*/
int				ft_atoi(const char *str);
int				ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);

#endif
