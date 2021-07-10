/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:58:01 by mscot             #+#    #+#             */
/*   Updated: 2020/12/08 16:58:03 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int	flag;
	int	num;

	flag = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		flag = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
		num = num * 10 + (*str++ - 48);
	return (num * flag);
}

int		ft_putchar_fd(char c, int fd)
{
	static int	count;
	int			return_value;

	if (fd < 0)
	{
		return_value = count;
		count = 0;
		return (return_value);
	}
	else
	{
		count++;
		write(fd, &(c), sizeof(char));
	}
	return (53);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		ft_putstr_fd("(null)", fd);
	else
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*sp;

	sp = (char *)s;
	while (*sp != c && *sp != '\0')
		sp++;
	if (*sp == c)
		return (sp);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (6);
	while (s[count] != '\0')
		count++;
	return (count);
}
