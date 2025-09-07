/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:42:03 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/06 02:00:05 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_duplicated(const int *list, int list_len)
{
	int	i;
	int	j;

	if (list_len == 1)
		return (1);
	i = 0;
	while (i < list_len - 1)
	{
		j = i + 1;
		while (j < list_len)
		{
			if (list[i] == list[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*only_zero(void)
{
	char	*ptr;

	ptr = malloc(2);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

int	valid_int_range(char *str, int sign, int digits)
{
	int		i;
	char	*max;
	char	*min;

	if (digits > 10)
		return (0);
	if (digits < 10)
		return (1);
	max = "2147483647";
	min = "-2147483648";
	i = 0;
	while (str[i + sign])
	{
		if (str[0] == '-' && str[i + sign] < min[i + sign])
			return (1);
		else if (str[0] != '-' && str[i + sign] < max[i])
			return (1);
		else if (str[0] == '-' && str[i + sign] > min[i + sign])
			return (0);
		else if (str[0] != '-' && str[i + sign] > max[i])
			return (0);
		i++;
	}
	return (1);
}

char	*trim_integer(const char *str, int sign)
{
	int		i;
	char	*trimmed_str;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		sign = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (!str[i])
		return (only_zero());
	else if ((str[i] == '+' || str[i] == '-') && !sign)
		return (NULL);
	trimmed_str = malloc(ft_strlen(&str[i]) + sign + 1);
	if (!trimmed_str)
		return (NULL);
	if (sign)
		trimmed_str[0] = str[0];
	ft_memcpy(&trimmed_str[sign], &str[i], ft_strlen(&str[i]) + 1);
	return (trimmed_str);
}

int	is_valid_integer(char **argv, char *str, int *arg_list, int prog_nm)
{
	int	i;
	int	sign;

	if (!str[0])
		return (0);
	i = 0;
	sign = 0;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		sign = 1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	str = trim_integer(str, 0);
	if (!str)
		free_exit(argv, str, arg_list, prog_nm);
	if (!valid_int_range(str, sign, ft_strlen(str) - sign))
		return (free(str), 0);
	return (free(str), 1);
}
