/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:19:46 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 01:19:46 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*findnuminrange(t_list *a, int max)
{
	int	num;

	num = a->val;
	if (num < max)
		return (a);
	a = a->next;
	while (a->val != num)
	{
		if (a->val < max)
			return (a);
		a = a->next;
	}
	return (NULL);
}

t_list	*findnumrev(t_list *a, int max)
{
	int	num;

	if (a->val < max)
		return (a);
	num = a->val;
	a = a->prev;
	while (a->val != num)
	{
		if (a->val < max)
			return (a);
		a = a->prev;
	}
	return (NULL);
}

int	findrelpos(t_list *a, int val)
{
	int		i;
	t_list	*t;

	i = 0;
	t = a;
	if (a->val == val)
		return (i);
	a = a->next;
	while (a != t)
	{
		i++;
		if (a->val == val)
			return (i);
		a = a->next;
	}
	return (-1);
}

int	findmax(t_list *b, t_list *t)
{
	int	ret;

	ret = b->val;
	b = b->next;
	while (b != t)
	{
		if (b->val > ret)
			ret = b->val;
		b = b->next;
	}
	return (ret);
}

int	findmin(t_list *b, t_list *t)
{
	int	ret;

	ret = b->val;
	b = b->next;
	while (b != t)
	{
		if (b->val < ret)
			ret = b->val;
		b = b->next;
	}
	return (ret);
}
