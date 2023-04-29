/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:56:23 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 01:56:23 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(int *len, int *chunks, int *chunksz, t_list *a)
{
	*len = ft_size(a);
	*chunks = getchunks(a);
	*chunksz = *len / *chunks;
	return (0);
}

void	bigsort(t_list *a, t_list *b, t_stackpos *positions)
{
	int		len;
	int		chunks;
	int		chunksz;
	int		min;
	int		max;

	min = init(&len, &chunks, &chunksz, a);
	max = chunksz;
	while (ft_size(a) != 0)
	{
		if (max == len)
		{
			maxlen(a, b, positions);
			break ;
		}
		if (hold_fs(a, max))
		{
			min = minmaxmanip(&min, &max, chunksz, len);
			continue ;
		}
		cf(a, b, max, positions);
		a = positions->a;
		b = positions->b;
	}
	emptyb(b, a, positions);
}

void	checkandsort(t_list *a, t_list *b, int len, t_stackpos *positions)
{
	if (is_sorted(a))
	{
		ft_free(a);
		return ;
	}
	if (len <= 3)
	{
		sort3(a, len, positions);
		a = positions->a;
	}
	else if (len <= 5)
	{
		sort54(a, b, positions);
		a = positions->a;
		b = positions->b;
	}
	else
	{
		bigsort(a, b, positions);
		a = positions->a;
		b = positions->b;
	}
	ft_free(a);
}

int	errorandsort(int *temp, int cnt)
{
	if (ft_error(temp, cnt))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	return (1);
}
