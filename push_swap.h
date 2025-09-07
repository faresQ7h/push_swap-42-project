/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:34:54 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/07 17:51:31 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*pre;
	int				value;
	int				cost;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	char			name;
}					t_stack;

void				free_exit(char **list, char *ptr, int *arg_list, int argv);
void				free_stack(t_stack *stack);
t_stack				*create_stack(int *list, int list_len, char c);
int					no_duplicated(const int *list, int list_len);
char				*trim_integer(const char *str, int sign);
int					is_valid_integer(char **argv, char *str, int *arg_list,
						int prog_nm);
void				swap_s(t_stack *s);
void				push_p(t_stack *s1, t_stack *s2);
void				rotate_r(t_stack *s, int silent);
void				rev_rotate_rr(t_stack *s, int silent);
void				rr_rrr(t_stack *s1, t_stack *s2, int rr, int rrr);
int					is_sorted(t_stack *s, int rev_order);
void				sort_stack(t_stack *a, t_stack *b);
t_node				*closest_target(int val, t_node *last, t_node *target,
						int is_min);
void				set_cost(t_node *temp);
int					top_path(t_node *temp, int is_up);
void				sort_short_stack(t_stack *s);
t_node				*min_node(t_stack *s);
t_node				*cheap_cost(t_stack *s);
void				to_top(t_stack *s1, t_node *cheap, t_stack *s2);

#endif