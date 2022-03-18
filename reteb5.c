/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reteb5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:04:44 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/18 18:25:39 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	riglpos(int pos, int *drp, int i)
{
	if (pos < (i / 2))
	{
		*drp = 1;
		return (pos);
	}
	*drp = 0;
	return (i - pos);
}

int	pos_of_minelem(t_stack **stack, int *drp)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		pos;

	tmp = *stack;
	i = 0;
	pos = 0;
	min = tmp -> content;
	while (1)
	{
		if (tmp -> content < min)
		{
			min = tmp -> content;
			pos = i;
		}
		tmp = tmp -> next;
		i++;
		if (tmp == *stack)
			break ;
	}
	return (riglpos(pos, drp, i));
}

void	retebfive(t_stack **stacka)
{
	int	drp;
	int	pos;
	int	i;

	pos = pos_of_minelem(stacka, &drp);
	if (drp == 1)
	{
		i = 0;
		while (i < pos)
		{
			rotate(stacka, 'a');
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < pos)
		{
			revrot(stacka, 'a');
			i++;
		}
	}
}

void	push_to_b(t_stack **stacka, t_stack **stackb)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		retebfive(stacka);
		push(stacka, stackb, 'b');
		i++;
	}
}

void	simple_sort(t_stack **stacka, t_stack **stackb)
{
	int	*tab;
	int	i;

	push_to_b(stacka, stackb);
	tab = largest2(*stacka, 4, &i);
	free(tab);
	push_elem_in_head(stacka, minelem(*stacka), 'a');
	push(stackb, stacka, 'a');
	push(stackb, stacka, 'a');
}
