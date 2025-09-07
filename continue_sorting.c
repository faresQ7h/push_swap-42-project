/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:23:01 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/07 19:55:16 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_node(t_stack *s)
{
	t_node	*min;
	t_node	*temp;

	min = s->head;
	temp = s->head->next;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_node	*cheap_cost(t_stack *s)
{
	t_node	*temp;
	t_node	*cheap;

	temp = s->head;
	cheap = s->head;
	while (temp)
	{
		set_cost(temp);
		temp = temp->next;
	}
	temp = s->head->next;
	while (temp)
	{
		if (cheap->cost > temp->cost)
			cheap = temp;
		temp = temp->next;
	}
	return (cheap);
}

void	sort_short_stack(t_stack *s)
{
	int		max;
	t_node	*temp;

	max = s->head->value;
	temp = s->head;
	while (temp->next)
	{
		if (temp->next->value > max)
			max = temp->next->value;
		temp = temp->next;
	}
	if (s->head->value == max && s->tail->value > s->tail->pre->value)
	{
		rotate_r(s, 0);
		return ;
	}
	while (!is_sorted(s, 0))
	{
		if (s->head->value > s->head->next->value)
			swap_s(s);
		else
			rev_rotate_rr(s, 0);
	}
}
