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
		printf("%d ", s[i]);
		i++;
	}
	printf("\n");
}

void	displaydll(t_list *p)
{
	int	num;

	if (!p)
	{
		printf("\n");
		return ;
	}
	num = p->val;
	printf("\n%d ", num);
	p = p->next;
	while (p && p->val != num)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	return ;
}
