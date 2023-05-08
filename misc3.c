/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:17:41 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 02:17:41 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	int	num;

	if (ft_size(a) <= 1)
		return (1);
	num = a->val;
	while (a->next->val != num)
	{
		if (a->next->val < a->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	getchunks(t_list *a)
{
	int	sz;

	sz = ft_size(a);
	if (sz > 5 && sz < 100)
		return (sz / 4);
	else if (sz >= 100 && sz < 500)
		return (sz / 20);
	else
		return (sz / 45);
}

int	signanddig(char **s, int j, int k)
{
	if (ft_issign(s[j][k]))
	{
		if (k == 0)
			k++;
		else
			return (0);
	}
	if (!ft_isdigit(s[j][k]))
		return (0);
	return (1);
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
	if (ft_strlen(s1) > 0)
		free ((char *)s1);
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
	s = ft_split(str, ' ', cnt);
	free(str);
	return (s);
}
