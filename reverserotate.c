/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:26:57 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/14 17:06:27 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	revrot(t_stack **stack, char c)
{
	t_stack	*temp;

	temp = *stack;
	while (temp -> next != *stack)
		temp = temp -> next;
	*stack = temp;
	if (c == 'a')
		ft_putstr("rra\n");
	if (c == 'b')
		ft_putstr("rrb\n");
}

void	revrot2(t_stack **stack_a, t_stack **stack_b)
{
	revrot(stack_a, 'c');
	revrot(stack_b, 'c');
	ft_putstr("rrr\n");
}
