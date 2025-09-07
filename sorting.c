/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:43:40 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/07 19:36:42 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*closest_target(int val, t_node *last, t_node *target, int is_min)
{
	t_node	*max;
	t_node	*min;

	max = target;
	min = target;
	while (target)
	{
		if (target->value > max->value)
			max = target;
		if (target->value < min->value)
			min = target;
		if (is_min && target->value < val && (!last
				|| last->value < target->value))
			last = target;
		else if (!is_min && target->value > val && (!last
				|| last->value > target->value))
			last = target;
		target = target->next;
	}
	if (!last && is_min)
		last = max;
	if (!last && !is_min)
		last = min;
	return (last);
}

int	top_path(t_node *temp, int is_up)
{
	int	i;

	if (is_up)
	{
		i = 0;
		temp = temp->pre;
		while (temp)
		{
			i++;
			temp = temp->pre;
		}
	}
	else
	{
		i = 1;
		temp = temp->next;
		while (temp)
		{
			i++;
			temp = temp->next;
		}
	}
	return (i);
}

void	set_cost(t_node *temp)
{
	int	down_total;
	int	up_total;
	int	down_up;
	int	up_down;

	if (top_path(temp, 0) > top_path(temp->target, 0))
		down_total = top_path(temp, 0);
	else
		down_total = top_path(temp->target, 0);
	if (top_path(temp, 1) > top_path(temp->target, 1))
		up_total = top_path(temp, 1);
	else
		up_total = top_path(temp->target, 1);
	down_up = top_path(temp, 0) + top_path(temp->target, 1);
	up_down = top_path(temp, 1) + top_path(temp->target, 0);
	temp->cost = down_total;
	if (temp->cost > up_total)
		temp->cost = up_total;
	if (temp->cost > down_up)
		temp->cost = down_up;
	if (temp->cost > up_down)
		temp->cost = up_down;
}

void	continue_to_top(t_stack *s1, t_node *cheap, t_stack *s2)
{
	if (top_path(cheap, 1) <= top_path(cheap->target, 1)
		&& cheap->cost == top_path(cheap->target, 1))
	{
		while (cheap != s1->head)
			rr_rrr(s1, s2, 1, 0);
		while (cheap->target != s2->head)
			rotate_r(s2, 0);
	}
	else if (top_path(cheap, 1) > top_path(cheap->target, 1)
		&& cheap->cost == top_path(cheap, 1))
	{
		while (cheap->target != s2->head)
			rr_rrr(s1, s2, 1, 0);
		while (cheap != s1->head)
			rotate_r(s1, 0);
	}
	else if (cheap->cost == top_path(cheap, 0) + top_path(cheap->target, 1))
	{
		while (cheap != s1->head)
			rev_rotate_rr(s1, 0);
		while (cheap->target != s2->head)
			rotate_r(s2, 0);
	}
}

void	to_top(t_stack *s1, t_node *cheap, t_stack *s2)
{
	if (top_path(cheap, 0) > top_path(cheap->target, 0)
		&& cheap->cost == top_path(cheap, 0))
	{
		while (cheap->target != s2->head)
			rr_rrr(s1, s2, 0, 1);
		while (cheap != s1->head)
			rev_rotate_rr(s1, 0);
	}
	else if (top_path(cheap, 0) <= top_path(cheap->target, 0)
		&& cheap->cost == top_path(cheap->target, 0))
	{
		while (cheap != s1->head)
			rr_rrr(s1, s2, 0, 1);
		while (cheap->target != s2->head)
			rev_rotate_rr(s2, 0);
	}
	else if (cheap->cost == top_path(cheap, 1) + top_path(cheap->target, 0))
	{
		while (cheap != s1->head)
			rotate_r(s1, 0);
		while (cheap->target != s2->head)
			rev_rotate_rr(s2, 0);
	}
	else
		continue_to_top(s1, cheap, s2);
}
