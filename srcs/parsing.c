/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:46:40 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/04 17:48:43 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

static int	ft_is_sep(char *str, char charset)
{
	if (*str == charset)
		return (1);
	return (0);
}

static int	ft_ltrcnt(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_is_sep(str + i, charset)))
		i++;
	return (i);
}

static int	ft_wrdcnt(char *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		if (*str && ft_is_sep(str, charset))
			str++;
		i = ft_ltrcnt(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_wdcpy(char *str, int size)
{
	char	*dest;

	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = str[size];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = ft_wrdcnt((char *)s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		while (*s && ft_is_sep((char *)s, c))
			s++;
		j = ft_ltrcnt((char *)s, c);
		str[i] = ft_wdcpy((char *)s, j);
		if (str[i] == NULL)
			return (NULL);
		s += j;
		i++;
	}
	str[size] = 0;
	return (str);
}

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

//libft///////////////////////////////////////////////////////////////////////////////

int	check_overflow(long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	ft_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	check_doublon(char **av)
{
	int	i;
	int	j;
	int	len;

	len = ft_len(av);
	i = 1;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_num(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!ft_isalnum(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_zero(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] == '0')
	{
		i++;
	}
	if (av[i] == '\0')
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

int	check_arg(char **av)
{
	int	i;
	long	tmp;

	i = 1;
	if (check_doublon(av))
		return (0);
	while (av[i])
	{
		if (!check_num(av[i]))
			return (0);
		// if (!check_zero(av[i]))
		// 	return (0);
		tmp = ft_atol(av[i]);
		if (!check_overflow(tmp))
			return (0);
		i++;
	}
	return (1);
}