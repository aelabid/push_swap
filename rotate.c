/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:21:25 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/05 16:45:07 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	rotate(t_stack **stack, char c)
{
	*stack = (*stack) -> next;
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
}

void	rotate2(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	printf("rr\n");
}