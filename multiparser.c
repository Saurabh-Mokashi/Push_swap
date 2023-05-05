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
	// ft_printf("first %s",agv[0]);
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
		// (*cnt)++;
	}
	// ft_printf("hi\n");
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
		s = concatandsplit(agv,ac,cnt);
		if (!multimparser(ac, j, cnt, s))
		{
			ft_printf("cnt val is %d\n",*cnt);
			free(s);
			return (0);
		}
	}
	free(s);
	// ft_printf("cnt val is %d\n",*cnt);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		l;
	int		r;
	int		len;

	l = 0;
	r = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s1[l] != '\0')
		str[i++] = s1[l++];
	while (s2[r] != '\0')
		str[i++] = s2[r++];
	str[i] = '\0';
	return (str);
}

char	**concatandsplit(char **agv, int ac, int *cnt)
{
	char	*str;
	char	**s;
	int		i;

	i = 1;
	str = "";
	while (i < ac)
	{
		str = ft_strjoin(str, agv[i]);
		str = ft_strjoin(str, (char *)" ");
		i++;
	}
	// ft_printf("Str now is %s\n",str);
	s = ft_split(str, ' ', cnt);
	// ft_printf("cnt is %d\n",*cnt);
	free(str);
	return (s);
}