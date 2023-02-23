/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:48 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/14 15:37:48 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
			// if (ft_issign(s[j][k]))
			// {
			// 	if (k == 0)
			// 		k++;
			// 	else
			// 	{
			// 		free(s);
			// 		s = NULL;
			// 		return (0);
			// 	}
			// }
			// if (!ft_isdigit(s[j][k]))
			// {
			// 	free(s);
			// 	s = NULL;
			// 	return (0);
			// }
int	multi2parser(char **s, int j, int k)
{
	j = 0;
	k = 0;
	while (s[j] != NULL)
	{
		while (s[j][k] != '\0')
		{
			if (!signanddig(s, j, k))
				return (0);
			k++;
		}
	j++;
	k = 0;
	}
	return (1);
}

		// j = 0;
		// k = 0;
		// while (s[j] != NULL)
		// {
		// 	while (s[j][k] != '\0')
		// 	{
		// 		if (ft_issign(s[j][k]))
		// 		{
		// 			if (k == 0)
		// 				k++;
		// 			else
		// 			{
		// 				free(s);
		// 				s = NULL;
		// 				return (0);
		// 			}
		// 		}
		// 		if (!ft_isdigit(s[j][k]))
		// 		{
		// 			free(s);
		// 			s = NULL;
		// 			return (0);
		// 		}
		// 		k++;
		// 	}
		// j++;
		// k = 0;
		// }

int	multimparser(int ac, int j, int *cnt, char **agv)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (agv[i][j] != '\0')
		{
			if (ft_issign(agv[i][j]))
			{
				if (j == 0)
					j++;
				else
					return (0);
			}
			if (!ft_isdigit(agv[i][j]))
				return (0);
			j++;
		}
		i++;
		(*cnt)++;
	}
	return (1);
}

void	splfree(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	goto2(char **agv, int *cnt, int j)
{
	char	**s;
	int		k;
	int		i;

	i = 0;
	s = ft_split(agv[1], ' ', cnt);
	if (!multi2parser(s, j, k))
	{
		splfree(s);
		return (0);
	}
	splfree(s);
	return (1);
}

int	multiparser(char **agv, int ac, int *cnt)
{
	int		j;

	if (ac == 2)
	{
		return (goto2(agv, cnt, j));
	}
	else
	{
		if (!multimparser(ac, j, cnt, agv))
			return (0);
	}
	return (1);
}

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
