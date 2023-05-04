/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:34:10 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 01:34:10 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delalloc(int *del, int *temp, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		del[i] = temp[i];
		i++;
	}
}

void	swapping(int *del, int i, int pos, int low)
{
	int	t;

	t = del[i];
	del[i] = low;
	del[pos] = t;
}

void	delallocmanip(int *del, int *temp, int cnt)
{
	int	i;
	int	j;
	int	low;
	int	pos;

	i = 0;
	delalloc(del, temp, cnt);
	while (i < cnt)
	{
		j = i + 1;
		low = del[i];
		pos = i;
		while (j < cnt)
		{
			if (del[j] < low)
			{
				low = del[j];
				pos = j;
			}
			j++;
		}
		swapping(del, i, pos, low);
		i++;
	}
}
