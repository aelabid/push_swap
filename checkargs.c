/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:30 by aelabid           #+#    #+#             */
/*   Updated: 2022/02/23 21:09:03 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<ctype.h>
#include"pushswap.h"
void	error()
{
	printf("Error");
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	checkalpha(char **av)
{
	int	i;
	int	j;

	i = 1;

	while (av[i])
	{
		if ((av[i][0] == '+') || (av[i][0] == '-'))
			j = 1;
		else
			j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
				error();
			j++;
		}
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns2 = (unsigned char *)s2;
	ns1 = (unsigned char *)s1;
	i = 0;
	j = 0;
	while (ns1[i] || ns2[i])
	{
		if (ns1[i] == ns2[i])
			i++;
		else
		{
			j = ns1[i] - ns2[i];
			return (j);
		}
	}
	return (0);
}


void	checkdouble(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = ac - 1;
		while (j > i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error();
			j--;
		}
		i++;
	}
}

void	checkmaxint(char **av)
{
	int	i;
	
	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) > 2147483647)
			error();
		if (ft_atoi(av[i]) < -2147483648)
			error();
		i++;
	}
}