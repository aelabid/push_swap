/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:50 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/18 21:50:01 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	checkvoid(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strncmp(av[i], "") == 0)
			error();
		i++;
	}
}

void	check2(int ac, char **av)
{
	checkalpha(av);
	checkdouble(ac, av);
	checkmaxint(av);
}

int	reteb(t_stack **stacka, t_stack **stackb, t_ij len_ac, int *tab)
{
	if (len_ac.i == len_ac.j - 1)
	{
		push_elem_in_head(stacka, minelem(*stacka), 'a');
		return (0);
	}
	pushtop(stackb, stacka, tab, len_ac);
	pushtoa(stacka, stackb);
	push_elem_in_head(stacka, minelem(*stacka), 'a');
	return (0);
}

void	freeall(t_stack **stacka, char **arg)
{
	t_stack	*emp;

	emp = *stacka;
	while (1)
	{
		free(emp);
		emp = emp->next;
		if (emp == *stacka)
			break ;
	}
	ft_free(arg);
}

int	main(int ac, char **av)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_ij	len_ac;
	int		*tab;
	char	**arg;

	checkvoid(av);
	if (ac > 1)
	{
		arg = convert(&ac, av);
		check2(ac, arg);
		if (ac == 1)
			return (0);
		len_ac.j = ac;
		stacka = fillstack(arg);
		if (ac == 6)
		{
			simple_sort(&stacka, &stackb);
			return (0);
		}
		tab = largest2(stacka, ac, &len_ac.i);
		reteb(&stacka, &stackb, len_ac, tab);
		free(tab);
		freeall(&stacka, arg);
	}
}
