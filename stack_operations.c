/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:54:00 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/07 19:09:50 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	free(stack);
}

int	add_node(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return (0);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	if (stack->size == 0)
	{
		new_node->pre = NULL;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->pre = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	new_node->cost = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->value = value;
	stack->size++;
	return (1);
}

t_stack	*create_stack(int *list, int list_len, char c)
{
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->name = c;
	if (!list && !list_len)
		return (stack);
	i = 0;
	while (i < list_len)
	{
		if (!add_node(stack, list[i]))
			return (free_stack(stack), NULL);
		i++;
	}
	return (stack);
}

void	continue_sorting(t_stack *a, t_stack *b, t_node *temp)
{
	while (b->size)
	{
		temp = b->head;
		temp->target = closest_target(temp->value, NULL, a->head, 0);
		while (temp->target != a->head)
		{
			if (top_path(temp->target, 1) <= top_path(temp->target, 0))
				rotate_r(a, 0);
			else
				rev_rotate_rr(a, 0);
		}
		push_p(a, b);
	}
	while (!is_sorted(a, 0))
	{
		if (top_path(min_node(a), 1) <= top_path(min_node(a), 0))
			rotate_r(a, 0);
		else
			rev_rotate_rr(a, 0);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size > 3)
		push_p(b, a);
	if (a->size > 3)
		push_p(b, a);
	while (a->size > 3)
	{
		temp = a->head;
		while (temp)
		{
			temp->target = closest_target(temp->value, NULL, b->head, 1);
			temp = temp->next;
		}
		to_top(a, cheap_cost(a), b);
		push_p(b, a);
	}
	sort_short_stack(a);
	continue_sorting(a, b, NULL);
}
