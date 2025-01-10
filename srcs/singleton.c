/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:38 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/12/26 20:50:45 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*_lst(void)
{
	static t_stack	stack;
	static int		init = 0;

	if (init == 0)
	{
		init = 1;
		stack.next = NULL;
		stack.prev = NULL;
	}
	return (&stack);
}
