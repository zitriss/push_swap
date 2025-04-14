/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:45:48 by tlize             #+#    #+#             */
/*   Updated: 2025/04/14 03:46:55 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_noeud **a, char **argv, char ***split_argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, split_argv);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, split_argv);
		if (error_duplicate(*a, (int)n))
			free_errors(a, split_argv);
		append_node(a, (int)n);
		i++;
	}
}

void	init_nodes_a(t_noeud *a, t_noeud *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_noeud *a, t_noeud *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
