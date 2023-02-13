/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:25:43 by rugrigor          #+#    #+#             */
/*   Updated: 2023/02/07 15:28:53 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int num, int *len)
{
	long	n;

	n = num;
	if (n < 0)
	{
		*len += ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_number(n / 10, len);
		ft_number(n % 10, len);
	}
	else
		*len += ft_putchar(n + 48);
}

void	ft_unsigned(unsigned int num, int *len)
{
	if (num > 9)
	{
		ft_unsigned(num / 10, len);
		ft_unsigned(num % 10, len);
	}
	else
		*len += ft_putchar(num + 48);
}

void	ft_hexadec(unsigned int hex, char c, int *len)
{
	char	*base;
	char	hex1[25];
	int		i;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (hex == 0)
		*len += ft_putchar('0');
	while (hex != 0)
	{
		hex1[i] = base[hex % 16];
		hex = hex / 16;
		i++;
	}
	while (i--)
		*len += ft_putchar(hex1[i]);
}

void	ft_pointer(unsigned long long p, int *len)
{
	char	*base;
	char	p1[25];
	int		i;

	*len += ft_putchar('0');
	*len += ft_putchar('x');
	i = 0;
	base = "0123456789abcdef";
	if (p == 0)
		*len += ft_putchar('0');
	while (p != 0)
	{
		p1[i] = base[p % 16];
		p = p / 16;
		i++;
	}
	while (i--)
		*len += ft_putchar(p1[i]);
}
