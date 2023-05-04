/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tog_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:35:49 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/13 00:35:49 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list	*a, t_list	*b)
{
	int	temp;

	temp = a->val;
	a->val = a->next->val;
	a->next->val = temp;
	temp = b->val;
	b->val = b->next->val;
	b->next->val = temp;
	ft_printf("ss\n");
}

void	rr(t_list	*a, t_list	*b, t_stackpos	*positions)
{
	positions->a = a->next;
	positions->b = b->next;
	ft_printf("rr\n");
}

void	rrr(t_list *a, t_list *b, t_stackpos *positions)
{
	positions->a = a->prev;
	positions->b = b->prev;
	ft_printf("rrr\n");
}

t_list	*abinit(int *temp, int cnt, t_list *a)
{
	t_list	*b;
	t_list	*tail;
	int		i;

	a = newdll(temp[0]);
	a->next = a;
	a->prev = a;
	b = a;
	i = 1;
	while (i < cnt)
	{
		tail = newdll(temp[i]);
		a->next = tail;
		tail->prev = a;
		a = tail;
		i++;
	}
	b->prev = a;
	a->next = b;
	a = a->next;
	b = NULL;
	return (a);
}
