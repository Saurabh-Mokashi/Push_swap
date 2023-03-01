/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:19:44 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 02:19:44 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newdll(int num)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list));
	t->val = num;
	t->prev = t;
	t->next = t;
	return (t);
}

int	getmindist(t_list *a)
{
	int	min;
	int	distance;
	int	ret;
	int	num;

	min = a->val;
	distance = 1;
	ret = 0;
	num = a->val;
	a = a->next;
	while (a && a->val != num)
	{
		if (a->val < min)
		{
			min = a->val;
			ret = distance;
		}
		distance++;
		a = a->next;
	}
	return (ret);
}

t_list	*len3(int first, int sec, int third, t_list *head)
{
	if (first < sec && sec > third)
	{
		if (first > third)
			head = rra(head);
		else
		{
			sa(head);
			head = ra(head);
		}
	}
	else if (first > sec && sec < third)
	{
		if (first < third)
			sa(head);
		else
			head = ra(head);
	}
	else
	{
		sa(head);
		head = rra(head);
	}
	return (head);
}

void	cf(t_list *a, t_list *b, int max, t_stackpos *p)
{
	int	sz;
	int	pos1;
	int	pos2;

	sz = ft_size(a);
	pos1 = findrelpos(a, findnuminrange(a, max)->val);
	pos2 = findrelpos(a, findnumrev(a->prev, max)->val);
	if (pos2 > (sz / 2))
		pos2 = sz - pos2;
	if (pos1 <= pos2)
		a = relposratimes(pos1, a);
	else
		a = relposrratimes(pos2, a);
	p = pb(a, b, p);
	a = p->a;
	b = p->b;
}
