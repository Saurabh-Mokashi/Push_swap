/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:57:16 by smokashi          #+#    #+#             */
/*   Updated: 2023/02/13 00:57:16 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# define MORE 2147483650

typedef struct t_list
{
	int				val;
	struct t_list	*next;
	struct t_list	*prev;
}	t_list;

typedef struct pos
{
	t_list	*a;
	t_list	*b;
}	t_stackpos;

int			ft_size(t_list *t);
int			is_sorted(t_list *a);
int			goto2(char **agv, int *cnt, int j);
void		main2(t_list *a);
void		main1(int *del, int *temp, int cnt);
t_list		*abinit(int *temp, int cnt, t_list *a);
int			init(int *len, int *chunks, int *chunksz, t_list *a);
void		checkandsort(t_list *a, t_list *b, int len, t_stackpos *positions);
int			errorandsort(int *temp, int cnt);
void		delalloc(int *del, int *temp, int cnt);
void		swapping(int *del, int i, int pos, int low);
void		delallocmanip(int *del, int *temp, int cnt);
t_list		*len3(int first, int sec, int third, t_list *head);
void		sa(t_list *top);
void		sb(t_list *top);
void		ss(t_list *a, t_list *b);
t_list		*ra(t_list *a);
t_list		*rb(t_list *b);
void		rr(t_list *a, t_list *b, t_stackpos *positions);
t_list		*rra(t_list *a);
t_list		*rrb(t_list *b);
void		rrr(t_list *a, t_list *b, t_stackpos *positions);
t_stackpos	*pa(t_list *a, t_list *b, t_stackpos *positions);
t_stackpos	*pb(t_list *a, t_list *b, t_stackpos *positions);
int			getwords(char *s, char c);
int			getchunks(t_list *a);
char		*memalloc(char *s, char c);
void		fn(char *s, char c, char **str);
char		**ft_split(char const *p, char c, int *cnt);
int			ft_issign(char c);
int			ft_isdigit(int c);
int			multiparser(char**agv, int ac, int *cnt);
int			multi2parser(char **s, int j, int k);
int			signanddig(char **s, int j, int k);
int			multimparser(int i, int j, int *cnt, char **agv);
int			postparser(int *temp, char **agv, int ac, int cnt);
int			postmparser(char **agv, int *temp, int ac);
int			post2parser(char **s, int *temp);
long		numcalc(char **s, int j);
int			ft_error(int *temp, int cnt);
void		display(int *s, int sz);
void		d(int *t);
void		displaydll(t_list *p);
t_stackpos	*posmanipa(t_stackpos *positions, t_list *a, t_list *b);
t_stackpos	*posmanipb(t_stackpos *positions, t_list *a, t_list *b);
t_list		*newdll(int num);
void		sort5(t_list *a, t_list *b, t_stackpos *positions);
void		sort100(t_list *head, int len);
void		sort500(t_list *head, int len);
void		sort3(t_list *head, int len, t_stackpos *positions);
void		sort54(t_list *a, t_list*b, t_stackpos *positions);
void		sort4(t_list *a, t_list *b, t_stackpos *positions);
void		bigsort(t_list *a, t_list *b, t_stackpos *positions);
void		checkandsort(t_list *a, t_list *b, int len, t_stackpos *positions);
void		splfree(char **s);
t_list		*findnuminrange(t_list *a, int max);
t_list		*findnumrev(t_list *a, int max);
int			findrelpos(t_list *a, int val);
int			findmax(t_list *b, t_list *t);
int			findmin(t_list *b, t_list *t);
t_list		*relposrrbtimes(int relpos, t_list *b);
t_list		*relposrbtimes(int relpos, t_list *b);
void		emptyb(t_list *b, t_list *a, t_stackpos *positions);
t_list		*relposratimes(int relpos, t_list *a);
t_list		*relposrratimes(int relpos, t_list *a);
void		ft_free(t_list *t);
int			hold_fs(t_list *a, int max);
void		maxlen(t_list *a, t_list *b, t_stackpos *positions);
int			minmaxmanip(int *min, int *max, int chunksz, int len);
void		cf(t_list *a, t_list *b, int max, t_stackpos *p);
int			getmindist(t_list *a);
void		sort5cont(t_list *a, t_list *b, t_stackpos *positions);
char		**concatandsplit(char **agv, int ac, int *cnt);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);

#endif