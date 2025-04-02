/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:15:35 by tlize             #+#    #+#             */
/*   Updated: 2024/11/27 15:42:28 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printfu(unsigned int n)
{
	int	count;

	if (n >= 10)
		count = ft_printfu(n / 10);
	else
		count = 0;
	return (count + ft_printfc(n % 10 + '0'));
}
