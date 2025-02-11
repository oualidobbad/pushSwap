/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:02 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:25:07 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	first = *stack;
	next = first->next;
	first->next = NULL;
	*stack = next;
	ft_push_back(stack, first);
}

void	rrb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	first = *stack;
	next = first->next;
	first->next = NULL;
	*stack = next;
	ft_push_back(stack, first);
}

void	rev_rotat(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'a')
	{
		rra(stack_a);
		ft_printf("rra\n");
	}
	else if (c == 'b')
	{
		rrb(stack_b);
		ft_printf("rrb\n");
	}
	else
	{
		rrb(stack_b);
		rra(stack_a);
		ft_printf("rrr\n");
	}
}
