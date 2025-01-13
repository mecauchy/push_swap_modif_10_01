/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:46 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/13 18:59:20 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *exit_msg)
{
	int	i;

	i = 0;
	while (exit_msg[i])
	{
		write(1, &exit_msg[i], 1);
		i++;
	}
	exit(0);
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

// void	initialize_index(t_stack *lst, int size)
// {
// 	t_stack	*tmp;
// 	int		max;
// 	max = 0;
// }

t_stack	*initialize_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	char	**new_lst;

	if (ac == 2)
	{
		new_lst = ft_split(av[1], ' ');
		stack_a = ft_lstnew(ft_atoi(new_lst[0]));
		i = 1;
	}
	else
	{
		new_lst = av;
		stack_a = ft_lstnew(ft_atoi(new_lst[1]));
		i = 2;
	}
	while (new_lst[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(new_lst[i])));
		i++;
	}
	if (ac == 2)
		ft_free(new_lst);
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
		ft_error("Error\n");
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
	else if (!is_sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// char	**args;
	// int		i;

	if (ac < 2)
		return (1);
	check_arg(ac, av);
	// args = parse_args(ac, av);
	// if (!args)
	// 	return (1);
	// if (ac == 2)
	// 	i = 0;
	// else
	// 	i = 1;
	// if (!check_arg(av + i))
	// {
	// 	ft_error("Error\n");
	// 	if (ac == 2)
	// 		ft_free(args);
	// 	return (1);
	// }
	//stack_a = _lst();
	//stack_a->nb = atoi(av[1]);
	stack_a = initialize_stack(ac, av);
	stack_b = NULL;
	print_lst(stack_a);
	printf("stack_b\n");
	print_lst(stack_b);
	push_swap(&stack_a, &stack_b);
	print_lst(stack_a);
	printf("stack_b\n");
	print_lst(stack_b);
	// SIMPLE SORT //
	// radix_sort(&stack_a, &stack_b, stack_size(stack_a))
	free_stack(&stack_a);
	free_stack(&stack_b);
	// if (ac == 2)
	// 	ft_free(args);
	return (0);
}
