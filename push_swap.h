/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:14:57 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/04 16:32:10 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				nb;
	int				index;
	int				rank;
	struct stack	*next;
}					t_stack;

t_stack				*ft_create_node(int nb);
void				ft_push_front(t_stack **begin_list, t_stack *new_node);
void				ft_push_back(t_stack **begin_list, t_stack *new_node);
t_stack				*ft_last_node(t_stack *head);
t_stack				*ft_push_nbr(t_stack *stack, char **nbr);
int					sa(t_stack **begin_stack);
int					sb(t_stack **begin_stack);
t_stack				*ft_list_at(t_stack *begin, int pos);
int					ft_list_size(t_stack *head);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				rotate(t_stack **stack_a, t_stack **stack_b, char a);
void				rev_rotat(t_stack **stack_a, t_stack **stack_b, char c);
bool				stack_sorted(t_stack *stack);
void				sort_three(t_stack **stack);
void				sort_stack(t_stack **stack);
void				set_rank(t_stack *stack);
t_stack				*get_min(t_stack *stack);
int					raje3_position(t_stack *stack, int rank);
void				sort_less_than7(t_stack **a, int size);
void				set_index(t_stack *stack);
void				free_nbr(char **nbr);
void				free_stack(t_stack **begin);
#endif