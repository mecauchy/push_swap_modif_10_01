/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:46 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/08 12:31:20 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *exit_msg, int exit_code)
{
	while (exit_msg)
	{
		write(1, exit_msg, 1);
		exit_msg++;
	}
	exit(exit_code);
}

char	**ft_free(char **to_free)
{
	int	i;

	i = 0;
	// if (!to_free)
	// 	return ;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
	return (NULL);
}	

t_stack	*initialize_stack(char **av)
{
	t_stack	*stack_a;
	int		i;

	stack_a = ft_lstnew(ft_atoi(av[1]));
	i = 2;
	while (av[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(av[i])));
		i++;
	}
	return (stack_a);
}

char	**parse_args(int ac, char **av)
{
	char	**argv;

	if (ac == 2)
	{
		argv = ft_split(av[1], ' ');
		if (!argv)
		{
			ft_putendl_fd("Error", 1);
			return (NULL);
		}
	}
	else if (ac > 2)
		argv = av;
	else
	{
		ft_error("Error", 0);
		return (NULL);
	}
	return (argv);
}

int	is_sorted(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1); // == trier
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (!is_sorted(stack_a) && stack_size == 2)
		sa(stack_a);
	else if (!is_sorted(stack_a) && stack_size == 3)
		sort_3(stack_a);
	else if (!is_sorted(stack_a) && stack_size <= 5)
		sort_5(stack_a, stack_b);
	// else if (!is_sorted(stack_a))
	// 	radix_sort(stack_a, stack_b);
	// else
	// {
	// 	free_stack(stack_a);
	// 	free_stack(stack_b);
	// }
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;

	if (ac < 2)
		return (1);
	args = parse_args(ac, av);
	if (!args)
		return (1);
	if (ac == 2)
		i = 0;
	else
		i = 1;
	if (!check_arg(av + i))
	{
		ft_error("Error", 0);
		if (ac == 2)
			ft_free(args);
		return (1);
	}
	//stack_a = _lst();
	//stack_a->nb = atoi(av[1]);
	stack_a = initialize_stack(args + i);
	stack_b = NULL;
	print_lst(stack_a);
	push_swap(&stack_a, &stack_b);
	print_lst(stack_a);
	// SIMPLE SORT //
	// radix_sort(&stack_a, &stack_b, stack_size(stack_a))
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ac == 2)
		ft_free(args);
	return (0);
}

