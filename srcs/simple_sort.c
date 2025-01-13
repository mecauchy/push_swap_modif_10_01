/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:22 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/13 18:58:59 by mcauchy-         ###   ########.fr       */
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

int	find_next_min(t_stack *stack_a, int min)
{
	int	next_min;

	next_min = stack_a->nb;
	while (stack_a)
	{
		if (stack_a->nb < next_min && next_min != min)
		{
			next_min = stack_a->nb;
			printf("===========next next next %d\n ======", next_min);
		}
		stack_a = stack_a->next;
	}
	return (next_min);
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

int	find_position(t_stack *stack_a, int min)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->nb == min)
			break ;
		index++;
		stack_a = stack_a->next;
	}
	return (index);
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->nb == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int min)
{
	int	pos;
	int	size;

	pos = find_position(*stack_a, min);
	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
	{
		while ((*stack_a)->nb != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->nb != min)
			rra(stack_a);
	}
	pb(stack_b, stack_a);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	next_min;

	if (ft_lstsize(*stack_a) > 5)
		return ;
	min = find_min(*stack_a);
	printf("=====min == %d\n", min);
	push_to_b(stack_a, stack_b, min);
	// next_min = find_next_min(*stack_a, min);
	next_min = find_min(*stack_a);
	push_to_b(stack_a, stack_b, next_min);
	printf("=======next min == %d\n", next_min);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	if (stack_a && (*stack_a) && (*stack_a)->next)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			sa(stack_a);
	}
}
