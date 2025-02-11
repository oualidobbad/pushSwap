/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:07:18 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:18:33 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack *head)
{
	int	i;

	i = 0;
	if (!head)
	{
		return (0);
	}
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_stack	*ft_list_at(t_stack *begin, int pos)
{
	int	i;

	i = 1;
	if (!begin)
		return (NULL);
	while (begin)
	{
		if (i == pos)
		{
			return (begin);
		}
		i++;
		begin = begin->next;
	}
	return (NULL);
}

t_stack	*ft_last_node(t_stack *head)
{
	if (!head)
	{
		return (NULL);
	}
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

t_stack	*ft_create_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->rank = -1;
	node->next = NULL;
	return (node);
}
