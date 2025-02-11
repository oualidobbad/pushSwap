/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:14 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:25:19 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*last_stack_b;
	t_stack	*prev_stack_a;
	int		size;

	size = ft_list_size(*stack_a);
	if (size <= 1)
		return ;
	last_stack_b = ft_list_at(*stack_a, size);
	prev_stack_a = ft_list_at(*stack_a, size - 1);
	prev_stack_a->next = NULL;
	ft_push_front(stack_a, last_stack_b);
}

void	rb(t_stack **stack_b)
{
	t_stack	*last_stack_b;
	t_stack	*prev_stack_b;
	int		size;

	size = ft_list_size(*stack_b);
	if (size <= 1)
		return ;
	last_stack_b = ft_list_at(*stack_b, size);
	prev_stack_b = ft_list_at(*stack_b, size - 1);
	prev_stack_b->next = NULL;
	ft_push_front(stack_b, last_stack_b);
}

void	rotate(t_stack **stack_a, t_stack **stack_b, char a)
{
	if (a == 'a')
	{
		ra(stack_a);
		ft_printf("ra\n");
	}
	else if (a == 'b')
	{
		rb(stack_b);
		ft_printf("rb\n");
	}
	else if (a == 'r')
	{
		rb(stack_b);
		ra(stack_a);
		ft_printf("rr\n");
	}
}
