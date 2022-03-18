/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:50 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/18 16:11:30 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	check2(int ac, char **av)
{
	checkalpha(av);
	checkdouble(ac, av);
	checkmaxint(av);
}

int	main(int ac, char **av)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_ij	len_ac;
	char	**arg;
	int		*tab;

	if (ac > 1)
	{
		av = convert(&ac, av);
		check2(ac, av);
		if (ac == 1)
			return (0);
		len_ac.j = ac;
		stacka = fillstack(av);
		if (ac == 6)
		{
			simple_sort(&stacka, &stackb, ac);
			return (0);
		}
		tab = largest2(stacka, ac, &len_ac.i);
		if (len_ac.i == ac - 1)
		{
			push_elem_in_head(&stacka, minelem(stacka), 'a');
			return (0);
		}
		pushtop(&stackb, &stacka, tab, len_ac);
		pushtoa(&stacka, &stackb);
		push_elem_in_head(&stacka, minelem(stacka), 'a');
	}
}
