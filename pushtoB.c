/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtoB.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:28:05 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/23 12:42:12 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	ifintab(int *tab, int val, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == val)
			return (1);
		i++;
	}
	return (0);
}

void	push_elem_in_head(t_stack **stack, int val, char ab)
{
	t_stack	*temp;
	int		i;
	int		bl;
	int		len;

	len = lenstack(*stack);
	i = 0;
	temp = *stack;
	while ((temp)->content != val)
	{
		temp = temp -> next;
		i++;
	}
	if (i > (len) / 2)
		bl = 0;
	else
		bl = 1;
	while (temp != *stack)
	{
		if (bl == 1)
			rotate(stack, ab);
		else
			revrot(stack, ab);
	}	
}

void	pushtop(t_stack **stack_b, t_stack **stack_a, int *tab, t_ij len_ac)
{
	t_stack	*temp;

	temp = *stack_a;
	while (1)
	{
		if (ifintab(tab, (temp)->content, len_ac.i) == 0)
		{
			push_elem_in_head(stack_a, (temp)->content, 'a');
			push(stack_a, stack_b, 'b');
			temp = *stack_a;
		}
		else
		{
			temp = temp -> next;
			if (*stack_a == temp)
				break ;
		}
	}
}
