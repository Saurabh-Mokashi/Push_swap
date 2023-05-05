/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:44 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/12 17:08:44 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main2(t_list *a)
{
	t_stackpos	*positions;
	t_list		*b;

	b = NULL;
	positions = malloc(sizeof(t_stackpos));
	positions->a = a;
	positions->b = NULL;
	checkandsort(a, b, ft_size(a), positions);
	free(positions);
}

void	main1(int *del, int *temp, int cnt)
{
	int		i;
	int		j;
	t_list	*a;

	i = 0;
	a = NULL;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt)
		{
			if (del[j] == temp[i])
			{
				temp[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	a = abinit(temp, cnt, a);
	main2(a);
}

void	main0(int ac, char **agv, int cnt, int *del)
{
	int	*temp;

	temp = malloc((cnt) * sizeof(int));
	if (!temp)
		return ;
	if (!postparser(temp, agv, ac, cnt))
	{
		free(temp);
		write (2, "Error\n", 6);
		return ;
	}
	if (!errorandsort(temp, cnt) || cnt == 0)
	{
		free(temp);
		return ;
	}
	del = malloc((cnt) * sizeof(int));
	if (!del)
		return ;
	delallocmanip(del, temp, cnt);
	main1(del, temp, cnt);
	free(del);
	free(temp);
}

int	main(int ac, char **agv)
{
	int			cnt;
	int			*del;

	cnt = 0;
	del = NULL;
	if (ac == 1)
		return (0);
	if (!multiparser(agv, ac, &cnt))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	main0(ac, agv, cnt, del);
}
