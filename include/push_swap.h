/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:16:00 by tlize             #+#    #+#             */
/*   Updated: 2025/04/02 17:16:45 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <../printf/ft_printf.h>
# include <../libft/libft.h>

typedef struct s_node
{
	int					value;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
	struct s_stack_node	*target;
}	t_node;
#endif
