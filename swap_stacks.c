/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:20 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:30:24 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **begin_stack)
{
	t_stack	*last;
	t_stack	*prev;
	t_stack	*before_prev;
	int		size;

	size = ft_list_size(*begin_stack);
	if (size < 2)
		return (0);
	prev = ft_list_at(*begin_stack, size - 1);
	last = ft_list_at(*begin_stack, size);
	if (size == 2)
	{
		last->next = prev;
		prev->next = NULL;
		*begin_stack = last;
	}
	else
	{
		before_prev = ft_list_at(*begin_stack, size - 2);
		before_prev->next = last;
		last->next = prev;
		prev->next = NULL;
	}
	return (ft_printf("sa\n"));
}

int	sb(t_stack **begin_stack)
{
	t_stack	*last;
	t_stack	*prev;
	t_stack	*before_prev;
	int		size;

	size = ft_list_size(*begin_stack);
	if (size < 2)
		return (0);
	prev = ft_list_at(*begin_stack, size - 1);
	last = ft_list_at(*begin_stack, size);
	if (size == 2)
	{
		last->next = prev;
		prev->next = NULL;
		*begin_stack = last;
	}
	else
	{
		before_prev = ft_list_at(*begin_stack, size - 2);
		before_prev->next = last;
		last->next = prev;
		prev->next = NULL;
	}
	return (ft_printf("sb\n"));
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
