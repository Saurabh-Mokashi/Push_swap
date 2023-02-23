/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:33:09 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/13 00:33:09 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list	*top)
{
	int	temp;

	if (ft_size(top) < 2)
		return ;
	temp = top->val;
	top->val = top->next->val;
	top->next->val = temp;
	printf("sa\n");
}

t_list	*ra(t_list	*a)
{
	a = a->next;
	printf("ra\n");
	return (a);
}

t_list	*rra(t_list *a)
{
	a = a->prev;
	printf("rra\n");
	return (a);
}

t_stackpos	*posmanipa(t_stackpos *positions, t_list *a, t_list *b)
{
	positions->a = a;
	positions->b = b;
	printf("pa\n");
	return (positions);
}

t_stackpos	*pa(t_list	*a, t_list	*b, t_stackpos	*positions)
{
	t_list	*t;

	if (ft_size(b) == 0)
		return (positions);
	t = newdll(b->val);
	if (a)
	{
		t->next = a;
		t->prev = a->prev;
		t->prev->next = t;
		a->prev = t;
	}
	a = t;
	t = b;
	b = b->next;
	t->next->prev = t->prev;
	t->prev->next = t->next;
	if (b == t)
	{
		free(b);
		b = NULL;
	}
	else
		free(t);
	return (posmanipa(positions, a, b));
}
	// positions->a = a;
	// positions->b = b;
	// printf("pa\n");

// if (b == t)
// 	{
// 		free(b);
// 		b = NULL;
// 	}
// 	else
// 		free(t);
// 	positions->a = a;
// 	positions->b = b;
// 	printf("pa\n");
// 	return (positions);