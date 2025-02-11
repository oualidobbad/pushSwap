/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:41 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:25:47 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

int	raje3_position(t_stack *stack, int rank)
{
	int	pos;

	pos = 1;
	while (stack)
	{
		if (stack->rank == rank)
		{
			pos = stack->index;
			return (pos);
		}
		stack = stack->next;
	}
	return (pos);
}

void	move_to_back(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	size = ft_list_size(*stack_b);
	while (*stack_b)
	{
		set_index(*stack_b);
		pos = raje3_position(*stack_b, size);
		if (pos <= size / 2 && ft_last_node(*stack_b)->rank != size)
			rev_rotat(stack_a, stack_b, 'b');
		else if (pos >= size / 2 && ft_last_node(*stack_b)->rank != size)
			rotate(stack_a, stack_b, 'b');
		if (ft_last_node(*stack_b)->rank == size)
		{
			pa(stack_a, stack_b);
			size--;
		}
	}
}

void	sorting_stack(t_stack **stack, float shank, t_stack *b, int i)
{
	set_rank(*stack);
	while (*stack)
	{
		if (ft_last_node(*stack) && ft_last_node(*stack)->rank < i)
		{
			pb(stack, &b);
			i++;
		}
		if (ft_last_node(*stack) && ft_last_node(*stack)->rank < (shank + i))
		{
			pb(stack, &b);
			if (ft_last_node(*stack) && ft_last_node(*stack)->rank >= (shank
					+ i))
				rotate(stack, &b, 'r');
			else
				rotate(stack, &b, 'b');
			i++;
		}
		else if (ft_last_node(*stack) && ft_last_node(*stack)->rank >= (shank
				+ i))
			rotate(stack, &b, 'a');
	}
	move_to_back(stack, &b);
}

void	sort_stack(t_stack **stack)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = ft_list_size(*stack);
	if (!stack || !*stack)
		return ;
	if (size == 2)
		sa(stack);
	else if (size == 3)
		sort_three(stack);
	else if (size <= 7)
		sort_less_than7(stack, size);
	else if (size <= 100)
		sorting_stack(stack, 10, b, 2);
	else
		sorting_stack(stack, 30, b, 1);
}
