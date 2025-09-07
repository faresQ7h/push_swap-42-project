/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:24:56 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/07 19:06:31 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s, int rev_order)
{
	t_node	*node_1;
	t_node	*node_2;

	if (!s || s->size < 2)
		return (1);
	node_1 = s->head;
	node_2 = s->head->next;
	while (node_2)
	{
		if (node_1->value > node_2->value && !rev_order)
			return (0);
		else if (node_1->value < node_2->value && rev_order)
			return (-1);
		node_1 = node_2;
		node_2 = node_1->next;
	}
	return (1);
}

void	free_exit(char **list, char *ptr, int *arg_list, int argv)
{
	int	i;

	if (!list && !argv)
	{
		i = 0;
		while (list[i])
			free(list[i++]);
	}
	if (!arg_list)
		free(arg_list);
	if (!ptr)
		free(ptr);
	if (!list)
		free(list);
	exit(1);
}

int	*parse_argv(int argc, char **argv, int *count, int prog_nm)
{
	int		*arg_list;
	char	*temp;
	int		i;

	arg_list = malloc(sizeof(int) * (argc)-prog_nm);
	if (!arg_list)
		exit(1);
	i = 0;
	while (argv[i + prog_nm])
	{
		if (is_valid_integer(argv, argv[i + prog_nm], arg_list, prog_nm))
		{
			temp = trim_integer(argv[i + prog_nm], 0);
			if (!temp)
				free_exit(argv, temp, arg_list, prog_nm);
			arg_list[i] = ft_atoi(temp);
			free(temp);
			(*count)++;
			i++;
		}
		else
			return (free(arg_list), NULL);
	}
	return (arg_list);
}

int	*parse_str(const char *str, int *n, int count, int new_word)
{
	char	**list;
	int		*arg_list;
	int		i;

	new_word = 1;
	i = 0;
	while (str[i])
	{
		if (str[i++] != ' ' && new_word)
		{
			count++;
			new_word = 0;
		}
		else
			new_word = 1;
	}
	list = ft_split(str, ' ');
	if (!list)
		exit(1);
	arg_list = parse_argv(count, list, n, 0);
	return (free(list), arg_list);
}

int	main(int argc, char **argv)
{
	int		*arg_list;
	int		count_out;
	t_stack	*a;
	t_stack	*b;

	count_out = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		arg_list = parse_str(argv[1], &count_out, 0, 0);
	else
		arg_list = parse_argv(argc, argv, &count_out, 1);
	if (!arg_list)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!no_duplicated(arg_list, count_out))
		return (ft_putstr_fd("Error\n", 2), free(arg_list), 1);
	a = create_stack(arg_list, count_out, 'a');
	b = create_stack(NULL, 0, 'b');
	free(arg_list);
	if (!a || !b)
		return (free_stack(a), free_stack(b), 1);
	if (a->size < 2 || is_sorted(a, 0))
		return (free_stack(a), free_stack(b), 0);
	sort_stack(a, b);
	return (free_stack(a), free_stack(b), 0);
}
