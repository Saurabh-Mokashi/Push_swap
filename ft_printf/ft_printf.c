/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:21:13 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/10 17:46:56 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getform(va_list ptr, char c)
{
	int	len;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (c == 'p')
		len += ft_printp(va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (c == 'u')
		len += ft_putnbru(va_arg(ptr, unsigned int));
	else if (c == 'x')
		len += ft_hexlower(va_arg(ptr, unsigned int));
	else if (c == 'X')
		len += ft_hexhigher(va_arg(ptr, unsigned int));
	else if (c == '%')
		len += ft_percent();
	else
		len = 0;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start (ptr, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_getform(ptr, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
