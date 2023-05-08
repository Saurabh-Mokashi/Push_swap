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

int	multimparser(int ac, int j, int *cnt, char **agv)
{
	int		i;

	i = 0;
	(void) ac;
	while (i < *cnt)
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

	s = ft_split(agv[1], ' ', cnt);
	k = 0;
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
	char	**s;

	j = 0;
	if (ac == 2)
	{
		return (goto2(agv, cnt, j));
	}
	else
	{
		s = concatandsplit(agv, ac, cnt);
		if (!multimparser(ac, j, cnt, s))
		{
			splfree(s);
			return (0);
		}
	}
	splfree(s);
	return (1);
}
