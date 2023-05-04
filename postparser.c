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

	i = 1;
	while (i < ac)
	{
		num = numcalc(agv, i);
		if ((long)num > 2147483647 || (long)num < -2147483648)
			return (0);
		temp[i - 1] = (int)(num);
		i++;
	}
	return (1);
}

		// s = ft_split(agv[1], ' ', &cnt);
		// j = 0;
		// k = 0;
		// while (s[j] != NULL)
		// {
		// 	while (s[j][k] != '\0')
		// 	{
		// 		if (s[j][k] == '+' || s[j][k] == '-')
		// 		{
		// 			if (s[j][k] == '-')
		// 				sign = -1;
		// 			k++;
		// 		}
		// 		num = num * 10 + (s[j][k] - '0');
		// 		k++;
		// 	}
		// 	if ((long)num * sign > 2147483647 || (long)num * sign < -2147483648)
		// 		return (0);
		// 	temp[j] = (int)(num * sign);
		// 	num = 0;
		// 	j++;
		// 	sign = 1;
		// 	k = 0;
		// }
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
	if (ac == 2)
	{
		return (gotopost2(agv, cnt, temp));
	}
	else
	{
		if (!postmparser(agv, temp, ac))
			return (0);
	}
	return (1);
}
		// while (i < ac)
		// {
		// 	j = 0;
		// 	while (agv[i][j] != '\0')
		// 	{
		// 		if (agv[i][j] == '+' || agv[i][j] == '-')
		// 		{
		// 			if (agv[i][j] == '-')
		// 				sign = -1;
		// 			j++;
		// 		}
		// 		num = num * 10 + (agv[i][j] - '0');
		// 		j++;
		// 	}
		// 	temp[i - 1] = (num * sign);
		// 	num = 0;
		// 	i++;
		// 	sign = 1;
		// 	j = 0;
		// }

// int	postparcer(int *temp, char **agv, int ac, int cnt)
// {
// 	int		i;
// 	int		sign;
// 	int		j;
// 	int		k;
// 	long	num;
// 	char	**s;

// 	i = 1;
// 	sign = 1;
// 	num = 0;
// 	if (ac == 2)
// 	{
// 		s = ft_split(agv[1], ' ', &cnt);
// 		j = 0;
// 		k = 0;
// 		while (s[j] != NULL)
// 		{
// 			while (s[j][k] != '\0')
// 			{
// 				if (s[j][k] == '+' || s[j][k] == '-')
// 				{
// 					if (s[j][k] == '-')
// 						sign = -1;
// 					k++;
// 				}
// 				num = num * 10 + (s[j][k] - '0');
// 				k++;
// 			}
// 			if ((long)num * sign > 2147483647 || (long)num * sign < -2147483648)
// 				return (0);
// 			temp[j] = (int)(num * sign);
// 			num = 0;
// 			j++;
// 			sign = 1;
// 			k = 0;
// 		}
// 	}
// 	else
// 	{
// 		while (i < ac)
// 		{
// 			j = 0;
// 			while (agv[i][j] != '\0')
// 			{
// 				if (agv[i][j] == '+' || agv[i][j] == '-')
// 				{
// 					if (agv[i][j] == '-')
// 						sign = -1;
// 					j++;
// 				}
// 				num = num * 10 + (agv[i][j] - '0');
// 				j++;
// 			}
// 			temp[i - 1] = (num * sign);
// 			num = 0;
// 			i++;
// 			sign = 1;
// 			j = 0;
// 		}
// 	}
// 	return (1);
// }
