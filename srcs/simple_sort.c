/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:22 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/08 13:03:51 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max(t_stack *lst)
{
	int	max;

	max = lst->nb;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}

int	find_min(t_stack *stack_a)
{
	int	min;

	min = stack_a->nb;
	while (stack_a)
	{
		if (stack_a->nb < min)
			min = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (min);
}

int	max_bits(t_stack **lst)
{
	int	bits;
	int	max;

	bits = 0;
	max = find_max(*lst);
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void	sort_3(t_stack **lst)
{
	int	max;

	max = find_max(*lst);
	if ((*lst)->nb == max)
		ra(lst);
	else if ((*lst)->next->nb == max)
		rra(lst);
	if ((*lst)->nb > (*lst)->next->nb)
		sa(lst);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int min)
{
	while ((*stack_a)->nb != min)
		ra(stack_a); //on turne jusqu'a trover le plus petit
	pb(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	next_min;

	if (ft_lstsize(*stack_a) > 5)
		return ;
	min = find_min(*stack_a);
	push_to_b(stack_a, stack_b, min);
	next_min = find_min(*stack_a);
	push_to_b(stack_a, stack_b, next_min);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
