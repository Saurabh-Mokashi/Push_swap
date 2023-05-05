/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:20:28 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 02:20:28 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(int	*s, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		ft_printf("%d ", s[i]);
		i++;
	}
	ft_printf("\n");
}

void	displaydll(t_list *p)
{
	int	num;

	if (!p)
	{
		ft_printf("\n");
		return ;
	}
	num = p->val;
	ft_printf("\n%d ", num);
	p = p->next;
	while (p && p->val != num)
	{
		ft_printf("%d ", p->val);
		p = p->next;
	}
	ft_printf("\n");
	return ;
}

void	d(int *t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		ft_printf("%d ", t[i]);
		i++;
	}
	ft_printf("\n");
}
