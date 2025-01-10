/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:28 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/08 12:29:42 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_lst(void)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = _lst();
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void	*ft_memset(void	*b, int c, unsigned int n)
{
	unsigned char	*ptr;
	unsigned char	a;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)b;
	a = (unsigned char)c;
	while (n)
	{
		ptr[i] = a;
		i++;
		n--;
	}
	return (ptr);
}

void	ft_bzero(void *s, unsigned int n)
{
	ft_memset(s, 0, n);
}

void	print_lst(t_stack *lst)
{
	while (lst)
	{
		if (lst->next)
			printf("%d -> ", lst->nb);
		else
			printf("%d -> (null)\n", lst->nb);
		lst = lst->next;
	}
}

t_stack	*ft_lstnew(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	free_stack(t_stack **lst)
{
	t_stack	*to_free;

	while (*lst)
	{
		to_free = (*lst);
		*lst = (*lst)->next;
		free(to_free);
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_elm;

	last_elm = 0;
	if (lst)
	{
		if (*lst)
		{
			last_elm = ft_lstlast(*lst);
			last_elm->next = new;
		}
		else
			*lst = new;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!(tmp->next))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
