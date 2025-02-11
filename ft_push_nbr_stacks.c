/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_nbr_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:30:04 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:19:14 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fct_free(t_stack **begin, char **nbr)
{
	t_stack	*head;
	t_stack	*temp;

	head = *begin;
	if (!begin)
	{
		return ;
	}
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	free_nbr(nbr);
	begin = NULL;
}

static int	check_dublicated(t_stack *head)
{
	t_stack	*next;

	if (!head)
		return (0);
	while (head)
	{
		next = head->next;
		while (next)
		{
			if (head->nb == next->nb)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			next = next->next;
		}
		head = head->next;
	}
	return (1);
}

static t_stack	*ft_push_nbr_stack(t_stack *stack, char **nbr)
{
	int		flag;
	long	nb;
	t_stack	*new_node;
	int		i;

	i = 0;
	flag = 1;
	while (nbr[i])
	{
		nb = ft_atoi(nbr[i++], &flag);
		if (flag == 0 || nb < INT_MIN || nb > INT_MAX)
			return (fct_free(&stack, nbr), write(2, "Error\n", 6), NULL);
		new_node = ft_create_node(nb);
		if (!new_node)
			return (fct_free(&stack, nbr), NULL);
		ft_push_front(&stack, new_node);
	}
	if (check_dublicated(stack) == 0)
		return (fct_free(&stack, nbr), NULL);
	return (stack);
}

t_stack	*ft_push_nbr(t_stack *stack, char **nbr)
{
	if (!nbr || !*nbr)
	{
		if (nbr && !*nbr)
			free_nbr(nbr);
		free_stack(&stack);
		write(2, "Error\n", 6);
		exit(0);
	}
	stack = ft_push_nbr_stack(stack, nbr);
	if (stack == NULL)
		exit(0);
	return (stack);
}
