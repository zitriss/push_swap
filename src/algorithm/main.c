/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:49:13 by tlize             #+#    #+#             */
/*   Updated: 2025/04/14 03:50:02 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(int argc, char **argv,
			t_noeud **a, char ***split_argv)
{
	*split_argv = NULL;
	if (argc == 2)
	{
		*split_argv = ft_split(argv[1], ' ');
		argv = *split_argv;
	}
	init_stack_a(a, argv + 1, split_argv);
}

void	sort_stacks_if_needed(t_noeud **a, t_noeud **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_noeud	*a;
	t_noeud	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	initialize_stacks(argc, argv, &a, &split_argv);
	sort_stacks_if_needed(&a, &b);
	free_stack(&a);
	if (split_argv)
		free_split(split_argv);
	return (0);
}
