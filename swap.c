/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:47:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/07 17:04:53 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	swap(t_stack *stack, char ab)
{
	int	temp;
	temp = stack -> content;
	stack -> content = (stack -> next) -> content;
	(stack -> next) -> content = temp;
	if (ab == 'a')
		printf("sa\n");
	else if (ab == 'b')
		printf("sb\n");
}
void	swap3(t_stack *stack)
{
	int	temp;
	temp = stack -> content;
	stack -> content = (stack -> next) -> content;
	(stack -> next) -> content = temp;
}

void	swap2(t_stack *stack1, t_stack *stack2)
{
	swap(stack1, 'c');
	swap(stack2, 'c');
	printf("ss\n");
}