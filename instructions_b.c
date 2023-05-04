/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:37:43 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/13 00:37:43 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list	*top)
{
	int	temp;

	if (ft_size(top) < 2)
		return ;
	temp = top->val;
	top->val = top->next->val;
	top->next->val = temp;
	ft_printf("sb\n");
}

t_list	*rb(t_list	*b)
{
	b = b->next;
	ft_printf("rb\n");
	return (b);
}

t_list	*rrb(t_list	*b)
{
	b = b->prev;
	ft_printf("rrb\n");
	return (b);
}

t_stackpos	*posmanipb(t_stackpos *positions, t_list *a, t_list *b)
{
	positions->a = a;
	positions->b = b;
	ft_printf("pb\n");
	return (positions);
}

t_stackpos	*pb(t_list *a, t_list *b, t_stackpos *positions)
{
	t_list	*t;

	if (ft_size(a) == 0)
		return (positions);
	t = newdll(a->val);
	if (b)
	{
		t->next = b;
		t->prev = b->prev;
		t->prev->next = t;
		b->prev = t;
	}
	b = t;
	t = a;
	a = a->next;
	t->next->prev = t->prev;
	t->prev->next = t->next;
	if (a == t)
	{
		free(a);
		a = NULL;
	}
	else
		free(t);
	return (posmanipb(positions, a, b));
}
