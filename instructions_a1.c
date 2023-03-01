/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:45:20 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/23 01:45:20 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*relposratimes(int relpos, t_list *a)
{
	while (relpos)
	{
		a = ra(a);
		relpos--;
	}
	return (a);
}

t_list	*relposrratimes(int relpos, t_list *a)
{
	while (relpos)
	{
		a = rra(a);
		relpos--;
	}
	return (a);
}
