/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:22:26 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:22:32 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int		size_b;
	t_stack	*last_stack_b;
	t_stack	*prev_stack_b;

	if (!stack_b || !stack_a)
		return ;
	size_b = ft_list_size(*stack_b);
	if (size_b == 0)
		return ;
	if (size_b == 1)
	{
		ft_push_back(stack_a, *stack_b);
		*stack_b = NULL;
		ft_printf("pa\n");
		return ;
	}
	last_stack_b = ft_list_at(*stack_b, size_b);
	prev_stack_b = ft_list_at(*stack_b, size_b - 1);
	prev_stack_b->next = NULL;
	ft_push_back(stack_a, last_stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	t_stack	*last_stack_a;
	t_stack	*prev_stack_a;

	if (!stack_a)
		return ;
	size_a = ft_list_size(*stack_a);
	if (size_a == 0)
		return ;
	if (size_a == 1)
	{
		ft_push_back(stack_b, *stack_a);
		*stack_a = NULL;
		ft_printf("pb\n");
		return ;
	}
	last_stack_a = ft_list_at(*stack_a, size_a);
	prev_stack_a = ft_list_at(*stack_a, size_a - 1);
	prev_stack_a->next = NULL;
	ft_push_back(stack_b, last_stack_a);
	ft_printf("pb\n");
}
