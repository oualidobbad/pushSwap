/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:24:56 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:24:57 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rank(t_stack *stack)
{
	t_stack	*temp;
	int		i;
	t_stack	*min;

	temp = stack;
	if (!stack)
		return ;
	min = get_min(stack);
	i = 1;
	while (stack)
	{
		min->rank = i++;
		min = get_min(temp);
		stack = stack->next;
	}
}
