/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:58 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/10 17:48:09 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_percent(void)
{
	return (ft_putchar_fd('%', 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int	rec(long int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += rec(n / 10, fd);
	len += ft_putchar_fd(((long int)n % 10) + '0', fd);
	return (len);
}

int	ft_putnbr_fd(int p, int fd)
{
	long int	n;
	int			len;

	len = 0;
	if (p < 0)
	{
		if (p == -2147483648)
		{
			write (fd, "-2147483648", 11);
			return (11);
		}
		ft_putchar_fd('-', fd);
		n = (long int)(-1 * p);
		len = 1;
	}
	else
		n = (long int)(p);
	return (len + rec(n, fd));
}
