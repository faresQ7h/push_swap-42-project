/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:26:59 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/07 19:30:52 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *s)
{
	t_node	*temp;

	if (!s || s->size < 2)
		return ;
	temp = s->head->next;
	temp->pre = NULL;
	s->head->pre = temp;
	if (s->size > 2)
		temp->next->pre = s->head;
	s->head->next = temp->next;
	temp->next = s->head;
	if (s->size == 2)
		s->tail = s->head;
	s->head = temp;
	ft_printf("s%c\n", s->name);
}

void	push_p(t_stack *s1, t_stack *s2)
{
	t_node	*temp;

	if (!s1 || !s2 || !s2->size)
		return ;
	temp = s2->head;
	s2->head = s2->head->next;
	if (s2->head)
		s2->head->pre = NULL;
	else
		s2->tail = NULL;
	temp->next = s1->head;
	temp->pre = NULL;
	if (s1->size)
		s1->head->pre = temp;
	else
		s1->tail = temp;
	s1->head = temp;
	s2->size--;
	s1->size++;
	ft_printf("p%c\n", s1->name);
}

void	rotate_r(t_stack *s, int silent)
{
	t_node	*temp;

	if (!s || s->size < 2)
		return ;
	temp = s->head;
	s->head = s->head->next;
	temp->next = NULL;
	s->head->pre = NULL;
	s->tail->next = temp;
	temp->pre = s->tail;
	s->tail = temp;
	if (!silent)
		ft_printf("r%c\n", s->name);
}

void	rev_rotate_rr(t_stack *s, int silent)
{
	t_node	*temp;

	if (!s || s->size < 2)
		return ;
	temp = s->tail;
	s->tail = s->tail->pre;
	temp->pre = NULL;
	s->tail->next = NULL;
	temp->next = s->head;
	s->head->pre = temp;
	s->head = temp;
	if (!silent)
		ft_printf("rr%c\n", s->name);
}

void	rr_rrr(t_stack *s1, t_stack *s2, int rr, int rrr)
{
	if (rr && !rrr)
	{
		rotate_r(s1, 1);
		rotate_r(s2, 1);
		ft_printf("rr\n");
		return ;
	}
	else if (!rr && rrr)
	{
		rev_rotate_rr(s1, 1);
		rev_rotate_rr(s2, 1);
		ft_printf("rrr\n");
		return ;
	}
}
