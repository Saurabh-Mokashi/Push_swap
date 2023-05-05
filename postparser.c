/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:54:50 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/14 23:54:50 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long	numcalc(char **s, int j)
{
	int		k;
	int		sign;
	long	num;

	k = 0;
	sign = 1;
	num = 0;
	while (s[j][k] != '\0')
	{
		if (s[j][k] == '+' || s[j][k] == '-')
		{
			if (s[j][k] == '-')
				sign = -1;
			k++;
		}
		num = num * 10 + (s[j][k] - '0');
		if (k > 11)
			return ((long) MORE);
		k++;
	}
	return ((long)(num * sign));
}

int	post2parser(char **s, int *temp)
{
	long	num;
	int		j;

	j = 0;
	while (s[j] != NULL)
	{
		num = numcalc(s, j);
		if ((long)num > 2147483647 || (long)num < -2147483648)
			return (0);
		temp[j] = (int)(num);
		j++;
	}
	return (1);
}

int	postmparser(char **agv, int *temp, int ac)
{
	int		i;
	long	num;

	i = 0;
	while (i < ac)
	{
		num = numcalc(agv, i);
		if ((long)num > 2147483647 || (long)num < -2147483648)
			return (0);
		temp[i] = (int)(num);
		i++;
	}
	return (1);
}

int	gotopost2(char **agv, int cnt, int *temp)
{
	char	**s;

	s = ft_split(agv[1], ' ', &cnt);
	if (!post2parser(s, temp))
	{
		splfree(s);
		return (0);
	}
	splfree(s);
	return (1);
}

int	postparser(int *temp, char **agv, int ac, int cnt)
{
	char	**s;
	int		j;

	if (ac == 2)
	{
		return (gotopost2(agv, cnt, temp));
	}
	else
	{
		s = concatandsplit(agv, ac, &j);
		if (!postmparser(s, temp, cnt))
		{
			splfree(s);
			return (0);
		}
	}
	splfree(s);
	return (1);
}
