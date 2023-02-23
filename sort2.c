/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:09:23 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 02:09:23 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort54(t_list *a, t_list*b, t_stackpos *positions)
{
	if (ft_size(a) == 4)
		sort4 (a, b, positions);
	else if (ft_size(a) == 5)
		sort5(a, b, positions);
	else
		return ;
}

void	sort3(t_list *head, int len, t_stackpos *positions)
{
	int	first;
	int	sec;
	int	third;

	if (len == 2)
	{
		if (head->val > head->next->val)
			sa(head);
	}
	else if (len == 3)
	{
		first = head->val;
		sec = head->next->val;
		third = head->prev->val;
		if (first < sec && sec < third)
			return ;
		head = len3(first, sec, third, head);
		positions->a = head;
	}
}

void	sort4(t_list *a, t_list *b, t_stackpos *positions)
{
	int	dist;

	if (a->val == 0)
		dist = 0;
	else
		dist = getmindist(a);
	if (dist == 1)
		sa(a);
	else if (dist == 2)
	{
		a = ra(a);
		a = ra(a);
	}
	else if (dist == 3)
		a = rra(a);
	if (is_sorted(a))
		return ;
	positions = pb(a, b, positions);
	a = positions->a;
	b = positions->b;
	sort3(a, ft_size(a), positions);
	a = positions->a;
	positions = pa(a, b, positions);
	a = positions->a;
	b = positions->b;
}

void	sort5(t_list *a, t_list *b, t_stackpos *positions)
{
	int	dist;

	if (a->val == 0)
		dist = 0;
	else
		dist = getmindist(a);
	if (dist == 1)
		sa(a);
	else if (dist == 2)
	{
		a = ra(a);
		a = ra(a);
	}
	else if (dist == 3)
	{
		a = rra(a);
		a = rra(a);
	}
	else if (dist == 4)
		a = rra(a);
	if (is_sorted(a))
		return ;
	sort5cont(a, b, positions);
}

void	sort5cont(t_list *a, t_list *b, t_stackpos *positions)
{
	positions = pb(a, b, positions);
	a = positions->a;
	b = positions->b;
	sort4(a, b, positions);
	a = positions->a;
	b = positions->b;
	positions = pa(a, b, positions);
	a = positions->a;
	b = positions->b;
}
