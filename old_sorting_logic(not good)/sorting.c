/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:18:04 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/05 20:52:42 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*second_min(t_stack *s, t_node *curr_min)
{
	t_node	*sec_min;
	t_node	*temp;

	if (curr_min != s->head)
		sec_min = s->head;
	else
		sec_min = s->head->next;
	temp = sec_min;
	while (temp)
	{
		if (temp != curr_min && temp->value < sec_min->value)
			sec_min = temp;
		temp = temp->next;
	}
	return (sec_min);
}

t_node	*min_pos(t_stack *s)
{
	t_node	*temp;
	t_node	*min;

	temp = s->head;
	min = temp;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	do_up(t_stack *s, t_node *min)
{
	t_node	*sec_min;
	t_node	*temp;
	int		next_min;

	if (min == s->head)
		return ;
	sec_min = second_min(s, min);
	next_min = 0;
	while (min->pre != s->head)
		rotate_r(s);
	temp = s->head;
	while (temp != sec_min)
	{
		next_min++;
		temp = temp->next;
	}
	if (sec_min == s->head)
		swap_s(s);
	else if (next_min <= (s->size) / 2 + (s->size % 2))
		rotate_r(s);
	else
		swap_s(s);
}

void	min_to_top(t_stack *s, t_node *min)
{
	t_node	*temp;
	int		up;
	int		down;

	if (min == s->head)
		return ;
	temp = min;
	up = 0;
	while (temp->pre)
	{
		up++;
		temp = temp->pre;
	}
	down = s->size - up;
	if (up <= down)
		do_up(s, min);
	else
	{
		while (min != s->head)
			rev_rotate_rr(s);
	}
}


void	sort_stack(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3 && (!is_sorted(a, 0) || !is_sorted(a, 1)))
	{
		min = min_pos(a);
		min_to_top(a, min);
		push_p(b, a);
	}
	if (a->size <= 3 && !is_sorted(a, 0))
		sort_short_stack(a);
	while (b->size)
		push_p(a, b);
}
