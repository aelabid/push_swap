/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:21:25 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/14 17:06:20 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	rotate(t_stack **stack, char c)
{
	*stack = (*stack)->next;
	if (c == 'a')
		ft_putstr("ra\n");
	else if (c == 'b')
		ft_putstr("rb\n");
}

void	rotate2(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	ft_putstr("rr\n");
}
