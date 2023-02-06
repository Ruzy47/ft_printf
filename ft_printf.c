/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:16 by rugrigor          #+#    #+#             */
/*   Updated: 2023/02/06 19:09:37 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_string(char *args, int *len)
{
	if (!args)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	*len += write(1, args, ft_strlen(args));
}

int	ft_check(const char s, va_list args)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s == 's')
		ft_string(va_arg(args, char *), &len);
	else if (s == '%')
		len += ft_putchar('%');
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(args, int), &len);
	else if (s == 'u')
		ft_unsigned(va_arg(args, unsigned int), &len);
	else if (s == 'p')
		ft_pointer(va_arg(args, unsigned long long), &len);
	else if (s == 'x')
		ft_hexadec(va_arg(args, unsigned int), 'x', &len);
	else if (s == 'X')
		ft_hexadec(va_arg(args, unsigned int), 'X', &len);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		len;
	va_list	args;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i] && i < ft_strlen(s))
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_check(s[i], args);
			i++;
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
