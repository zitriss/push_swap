/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:34 by tlize             #+#    #+#             */
/*   Updated: 2025/02/03 11:59:29 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	*sw(int const *pile)
{
	int	*npile;
	int	swap;

       	npile = (int *)pile;
	swap = npile[0];
	npile[0] = npile[1];
	npile[1] = swap;
	return (npile);
}

void	swap(int *a, int *b, char arg)
{
	if (arg == 'a' || arg == 's')
		a = sw(a);
	if (arg == 'b' || arg == 's')
		b = sw(b);
}

int	main(void)
{
	int	test[] = [1,2,3,4,5,6,7];
	int	test2[] = [1,2,3,4,5];
	swap(test1, test2, 'a');
	printf("%s\n",	test1);
	printf("%s\n",	test2);
	return 0;
}
