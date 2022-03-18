/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:32:55 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/14 14:34:30 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	lenstack(t_stack *temp)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = temp;
	while (1)
	{
		i++;
		tmp = tmp -> next;
		if (tmp == temp)
			break ;
	}
	return (i);
}

int	bigelem(t_stack *temp)
{
	t_stack	*tmp;
	int		big;

	tmp = temp;
	big = temp -> content;
	while (1)
	{
		if (tmp -> content > big)
			big = tmp -> content;
		tmp = tmp -> next;
		if (temp == tmp)
			break ;
	}
	return (big);
}

int	right_number(t_stack *temp, int num)
{
	t_stack	*tmp;
	int		big;

	tmp = temp;
	big = bigelem(tmp);
	while (1)
	{
		if ((tmp->content > num) && (tmp->content < big))
		{
			big = tmp -> content;
		}
		tmp = tmp -> next;
		if (temp == tmp)
			break ;
	}
	return (big);
}

int	count_to_head(t_stack *tmp, int elem, int *rvrt, char ab)
{
	int		i;
	int		len;
	int		element;
	t_stack	*temp;

	temp = tmp;
	if (ab == 'b')
		element = elem;
	else
		element = right_number(temp, elem);
	len = lenstack(tmp);
	i = 0;
	while (temp -> content != element)
	{
		i++;
		temp = temp -> next;
	}
	if (i - 1 > len / 2)
	{
		*rvrt = 0;
		return (len - i);
	}
	*rvrt = 1;
	return (i);
}

void	reversrot(t_stack **stack_a, t_stack **stack_b, t_ij temp, t_ij rv)
{
	while (temp.i != (*stack_a)->content)
	{
		if (rv.i == 0)
			revrot(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
	while (temp.j != (*stack_b)->content)
	{
		if (rv.j == 0)
			revrot(stack_b, 'b');
		else
			rotate(stack_b, 'b');
	}
	push(stack_b, stack_a, 'a');
}
