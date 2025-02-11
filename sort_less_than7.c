/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:38:15 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 13:29:29 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_back_in_a(t_stack **a, t_stack *b)
{
	int	size;

	size = ft_list_size(b);
	while (size > 0)
	{
		pa(a, &b);
		size--;
	}
}

void	sorting_7nb(t_stack **a, t_stack *b, int i, int size)
{
	float	pos;

	set_rank(*a);
	while (size > 3)
	{
		set_index(*a);
		pos = raje3_position(*a, i);
		if (stack_sorted(*a))
			return (pa(a, &b), pa(a, &b));
		if (ft_last_node(*a)->rank == i)
		{
			pb(a, &b);
			i++;
			size--;
		}
		else if (pos < size / 2 && ft_last_node(*a)->rank != i)
			rev_rotat(a, &b, 'a');
		else if (pos >= size / 2 && ft_last_node(*a)->rank != i)
			rotate(a, &b, 'a');
	}
	sort_three(a);
	move_back_in_a(a, b);
}

void	sort_less_than7(t_stack **a, int size)
{
	t_stack	*b;

	b = NULL;
	if (!*a || !a)
		return ;
	sorting_7nb(a, b, 1, size);
}
