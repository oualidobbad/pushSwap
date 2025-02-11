/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:11:25 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:47:31 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	free_stack(t_stack **begin)
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
	begin = NULL;
}

void	free_nbr(char **nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		free(nbr[i++]);
	free(nbr);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	char	**nbr;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		nbr = ft_split(av[i], 32);
		stack_a = ft_push_nbr(stack_a, nbr);
		free_nbr(nbr);
		i++;
	}
	if (!stack_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
