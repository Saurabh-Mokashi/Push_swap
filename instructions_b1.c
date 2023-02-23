/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:45:39 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 01:45:39 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*relposrrbtimes(int relpos, t_list *b)
{
	relpos = ft_size(b) - relpos;
	while (relpos)
	{
		b = rrb(b);
		relpos--;
	}
	return (b);
}

t_list	*relposrbtimes(int relpos, t_list *b)
{
	while (relpos)
	{
		b = rb(b);
		relpos--;
	}
	return (b);
}

void	emptyb(t_list *b, t_list *a, t_stackpos *positions)
{
	int	ele;
	int	relpos;

	a = positions->a;
	b = positions->b;
	while (ft_size(b))
	{
		ele = findmax(b, b);
		relpos = findrelpos(b, ele);
		if (relpos > (ft_size(b) / 2))
			b = relposrrbtimes(relpos, b);
		else
			b = relposrbtimes(relpos, b);
		positions = pa(a, b, positions);
		a = positions->a;
		b = positions->b;
	}
}
