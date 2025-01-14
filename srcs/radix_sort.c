/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:17:44 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/14 18:34:19 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putback_in_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		pa(stack_b, stack_a);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	max;
	int	size;
	t_stack	*tmp;
	
	i = 0;
	size = ft_lstsize(*stack_a);
	max = max_bits(stack_a);
	while (i < max)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *stack_a;
			if (((tmp->nb >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		ft_putback_in_stack(stack_a, stack_b);
		i++;
	}
	while ((*stack_a)->nb != find_min(*stack_a))
		ra(stack_a);
}
