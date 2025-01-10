/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:56 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/10 12:43:22 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
// # include "./libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int nb);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);

void	print_lst(t_stack *lst);
void	ft_bzero(void *s, unsigned int n);

t_stack	*_lst(void);
void	free_lst(void);

int		swap(t_stack **lst);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **src, t_stack **dest);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **lst);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
void	ft_putendl_fd(char *s, int fd);
int		reverse_rotate(t_stack **lst);
t_stack	*lst_before_last(t_stack *lst);


//A SUPP LIBFT//
int	ft_isalnum(int c);
char	**ft_split(char const *s, char c);
// static char	*ft_wdcpy(char *str, int size);
// static int	ft_wrdcnt(char *str, char charset);
// static int	ft_ltrcnt(char *str, char charset);
// static int	ft_is_sep(char *str, char charset);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

int		check_overflow(long nb);
int		ft_len(char **av);
int		check_doublon(char **av);
int		check_num(char *av);
int		check_zero(char *av);
long	ft_atol(const char *str);
void	check_arg(int ac, char **av);

// PUSH_SWAP //

void	ft_error(char *exit_msg);
char	**ft_free(char **to_free);
t_stack	*initialize_stack(int ac, char **av);
char	**parse_args(int ac, char **av);
int		is_sorted(t_stack **lst);
void	push_swap(t_stack **stack_a, t_stack **stack_b);

// SIMPLE SORT //

int	find_max(t_stack *lst);
int	find_min(t_stack *stack_a);
int	max_bits(t_stack **lst);
void	sort_3(t_stack **lst);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

// UTILS //

void	free_stack(t_stack **lst);

#endif