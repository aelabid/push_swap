/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:15:29 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/14 12:54:26 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	*check(int ac, t_stack *temp, int *z)
{
	int	large;
	int	minlarge;
	int	j;
	int	*tab;

	*z = 0;
	j = 0;
	tab = malloc(ac * sizeof(int));
	large = temp -> content;
	minlarge = temp -> content;
	while (j < ac - 1)
	{
		if (temp -> content >= large)
		{
			large = temp -> content;
			tab[*z] = large;
			*z = *z + 1;
		}
		temp = temp -> next;
		j++;
	}
	return (tab);
}

int	*largest(t_stack *stack_a, int ac, int *num)
{
	t_ij	ij;
	int		*ftab;
	int		*tab;
	int		lng;

	ij.i = 0;
	lng = 0;
	ij.j = 0;
	*num = 0;
	while (ij.i < ac - 1)
	{
		tab = check(ac, stack_a, &ij.j);
		if (ij.j > lng)
		{
			if (lng != 0)
				free(ftab);
			lng = ij.j;
			ftab = check(ac, stack_a, &ij.j);
			*num = ij.j;
		}
		free(tab);
		stack_a = stack_a -> next;
		ij.i++;
	}
	return (ftab);
}

int	*largest2(t_stack *stack_a, int ac, int *num)
{
	t_stack	*temp;
	int		largs;
	int		largnos;
	int		*largtabs;
	int		*largtabnos;

	temp = stack_a;
	largtabnos = largest(stack_a, ac, &largnos);
	swap3(temp);

	largtabs = largest(temp, ac, &largs);
	swap3(temp);
	if (largnos >= largs)
	{
		*num = largnos;
		return (largtabnos);
	}
	*num = largs;
	swap(stack_a, 'a');
	return (largtabs);
}
