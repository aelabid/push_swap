/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:30:52 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/14 14:34:48 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	pushelm(t_stack **stack_a, t_stack **stack_b, t_ij temp)
{
	t_stack	*tempsa;
	t_stack	*tempsb;
	t_ij	rv;
	int		var;

	var = 0;
	tempsa = *stack_a;
	tempsb = *stack_b;
	count_to_head(tempsb, temp.j, &rv.j, 'b');
	count_to_head(tempsa, temp.j, &rv.i, 'a');
	while ((temp.j != (*stack_b)->content)
		&& (temp.i != (*stack_a)->content) && var == 0)
	{
		if ((rv.i == 0 && rv.j == 0) || (rv.i == 1 && rv.j == 1))
		{
			if (rv.i == 0 && rv.j == 0)
				revrot2(stack_a, stack_b);
			else if (rv.i == 1 && rv.j == 1)
				rotate2(stack_a, stack_b);
		}
		else
			var = 1;
	}
	reversrot(stack_a, stack_b, temp, rv);
}

int	minmvmnt(t_stack *lst)
{
	int		min;
	int		minval;
	t_stack	*temp;

	temp = lst;
	min = temp -> nbmvmnt;
	while (1)
	{		
		if (temp->nbmvmnt <= min)
		{
			min = temp->nbmvmnt;
			minval = temp->content;
		}
		temp = temp -> next;
		if (lst == temp)
			break ;
	}
	return (minval);
}

void	pushnbmvmnt(t_stack *stackb, t_stack *stacka)
{
	int		nbmva;
	int		nbmvb;
	int		bmna;
	int		bmnb;
	t_stack	*temp;

	temp = stackb;
	while (1)
	{
		nbmvb = count_to_head(stackb, temp -> content, &bmnb, 'b');
		nbmva = count_to_head(stacka, temp -> content, &bmna, 'a');
		if ((bmna == 0 && bmnb == 0) || (bmna == 1 && bmnb == 1))
		{
			if (nbmva > nbmvb)
				temp->nbmvmnt = nbmva;
			else
				temp->nbmvmnt = nbmvb;
		}		
		else
			temp->nbmvmnt = nbmva + nbmvb;
		temp = temp -> next;
		if (temp == stackb)
			break ;
	}
}

void	pushtoa(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_ij	tempab;

	temp = *stackb;
	pushnbmvmnt(*stackb, *stacka);
	temp2 = *stackb;
	while (*stackb != NULL)
	{
		if (temp -> content == minmvmnt(*stackb))
		{
			tempab.i = right_number(*stacka, temp->content);
			tempab.j = temp->content;
			pushelm(stacka, stackb,
				tempab);
			temp = *stackb;
			if (*stackb != NULL)
				pushnbmvmnt(*stackb, *stacka);
		}
		else
			temp = temp -> next;
	}
}
