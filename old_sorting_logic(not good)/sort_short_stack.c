void	sort_short_stack(t_stack *s)
{
	t_node	*temp;
	int		max;

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
		rotate_r(s);
		return ;
	}
	while (!is_sorted(s, 0))
	{
		if (s->head->value > s->head->next->value)
			swap_s(s);
		else
			rev_rotate_rr(s);
	}
}
