/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:17:41 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 02:17:41 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	int	num;

	if (ft_size(a) <= 1)
		return (1);
	num = a->val;
	while (a->next->val != num)
	{
		if (a->next->val < a->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	getchunks(t_list *a)
{
	int	sz;

	sz = ft_size(a);
	if (sz > 5 && sz < 100)
		return (sz / 4);
	else if (sz >= 100 && sz < 500)
		return (sz / 20);
	else
		return (sz / 45);
}

int	signanddig(char **s, int j, int k)
{
	if (ft_issign(s[j][k]))
	{
		if (k == 0)
			k++;
		else
			return (0);
	}
	if (!ft_isdigit(s[j][k]))
		return (0);
	return (1);
}
