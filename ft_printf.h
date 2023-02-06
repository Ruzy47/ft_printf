/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:08:28 by rugrigor          #+#    #+#             */
/*   Updated: 2023/02/06 19:09:44 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		ft_check(const char s, va_list args);
void	ft_string(char *args, int *len);
int		ft_putchar(char c);
void	ft_number(int num, int *len);
void	ft_unsigned(unsigned int num, int *len);
void	ft_hexadec(unsigned int hex, char c, int *len);
void	ft_pointer(unsigned long long p, int *len);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
