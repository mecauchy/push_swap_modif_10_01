/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:50 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/13 17:57:35 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	swap(t_stack **lst)
{
	t_stack	*head;
	t_stack	*tmp;
	int		swap;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	head = *lst;
	tmp = head->next;
	swap = head->nb;
	head->nb = tmp->nb;
	tmp->nb = swap;
	return (0);
}

int	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	else
		ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	else
		ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

// int	push(t_stack **dest, t_stack **src)
// {
// 	t_stack	*tmp;

// 	if (dest == NULL || src == NULL)
// 		return (-1);
// 	tmp = *dest;
// 	(*dest) = (*dest)->next;
// 	if (src == NULL)
// 		*src = tmp;
// 	else
// 	{
// 		tmp->next = *src;
// 		*src = tmp;
// 	}
// 	return (0);
// }

int	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return (-1);
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(t_stack **lst)
{
	t_stack	*stock;
	t_stack	*head;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	head = *lst;
	stock = ft_lstlast(head);
	*lst = head->next;
	head->next = NULL;
	stock->next = head;
	return (0);
}

t_stack	*lst_before_last(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->next->next == NULL)
		{
		//	lst->next = NULL;
			break ;
		}
		lst = lst->next;
	}
	return (lst);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverse_rotate(t_stack **lst)
{
	t_stack	*stock;
	t_stack	*head;
	t_stack	*before_last;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	head = ft_lstlast(*lst);
	before_last = lst_before_last(*lst);
	stock = *lst;
	*lst = head;
	(*lst)->next = stock;
	before_last->next = NULL;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	// if ((ft_listize(stack_a) < 2) || (ft_lstsize(stack_b) < 2))
	// 	return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
