/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:30:56 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:25:53 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos_max(t_stack *stack, int *pos_max)
{
	int	max;
	int	index;

	max = INT_MIN;
	index = 1;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			*pos_max = index;
		}
		index++;
		stack = stack->next;
	}
}

void	sort_three(t_stack **stack)
{
	int		pos_max;
	t_stack	*b;

	pos_max = 1;
	b = NULL;
	get_pos_max(*stack, &pos_max);
	if (!*stack || !stack)
		return ;
	if (pos_max == 2 && (*stack)->nb < (*stack)->next->next->nb)
		rev_rotat(stack, &b, 'a');
	else if ((*stack)->nb > (*stack)->next->next->nb && pos_max == 2)
	{
		rev_rotat(stack, &b, 'a');
		sa(stack);
	}
	else if (pos_max == 3 && (*stack)->nb > (*stack)->next->nb)
		rotate(stack, &b, 'a');
	else if (pos_max == 3 && (*stack)->nb < (*stack)->next->nb)
	{
		sa(stack);
		rev_rotat(stack, &b, 'a');
	}
	else
		sa(stack);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb < stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}
