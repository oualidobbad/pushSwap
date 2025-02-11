/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:22:05 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:22:06 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

t_stack	*get_max(t_stack *stack)
{
	t_stack	*node_max;

	if (!stack)
		return (NULL);
	node_max = stack;
	while (stack)
	{
		if (stack->nb > node_max->nb)
			node_max = stack;
		stack = stack->next;
	}
	return (node_max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*node_min;

	if (!stack)
		return (NULL);
	node_min = get_max(stack);
	while (stack)
	{
		if (stack->nb < node_min->nb && stack->rank == -1)
			node_min = stack;
		stack = stack->next;
	}
	return (node_min);
}
