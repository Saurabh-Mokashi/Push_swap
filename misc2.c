/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:04:43 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 02:04:43 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list *t)
{
	t_list	*s;
	t_list	*p;

	if (!t)
		return ;
	s = t->next;
	while (s != t)
	{
		p = s->next;
		free(s);
		s = p;
	}
	free(t);
}

int	hold_fs(t_list *a, int max)
{
	t_list	*hold_first;
	t_list	*hold_second;

	hold_first = findnuminrange(a, max);
	hold_second = findnumrev(a->prev, max);
	return (!hold_first && !hold_second);
}

void	maxlen(t_list *a, t_list *b, t_stackpos *positions)
{
	int	ele;
	int	relpos;

	while (a)
	{
		ele = findmax(a, a);
		relpos = findrelpos(a, ele);
		if (relpos > (ft_size(a) / 2))
			a = relposrratimes(relpos, a);
		else
			a = relposratimes(relpos, a);
		positions = pb(a, b, positions);
		a = positions->a;
		b = positions->b;
	}
}

int	minmaxmanip(int *min, int *max, int chunksz, int len)
{
	min = max;
	if (*max + chunksz < len)
		*max = *max + chunksz;
	else
		*max = len;
	return (*min);
}
