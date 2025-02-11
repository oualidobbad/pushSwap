/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:45:10 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:18:51 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_front(t_stack **begin_list, t_stack *new_node)
{
	if (!begin_list)
		return ;
	if (new_node)
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
	}
}

void	ft_push_back(t_stack **begin_list, t_stack *new_node)
{
	t_stack	*last;

	if (!begin_list)
		return ;
	if (!*begin_list)
	{
		*begin_list = new_node;
		return ;
	}
	last = ft_last_node(*begin_list);
	last->next = new_node;
}
