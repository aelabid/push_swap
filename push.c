/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:34:42 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/23 13:07:21 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	print(char ab)
{
	if (ab == 'b')
		ft_putstr("pb\n");
	else if (ab == 'a')
		ft_putstr("pa\n");
}

void	freea(t_stack **stack_a)
{
	free(*stack_a);
	*stack_a = NULL;
}

void	push(t_stack **stack_a, t_stack **stack_b, char ab)
{
	t_stack	*aux;
	t_stack	*temp;

	if (*stack_a != NULL)
	{
		print(ab);
		if (*stack_b == NULL)
			*stack_b = ft_lstnew((*stack_a)->content);
		else
		{
			temp = ft_lstnew((*stack_a)->content);
			temp -> next = *stack_b;
			ft_lstlast(*stack_b)->next = temp;
			*stack_b = temp;
		}
		aux = ft_lstlast(*stack_a);
		if (aux->next == aux)
		{
			freea(stack_a);
			return ;
		}
		aux -> next = (*stack_a)->next;
		free(*stack_a);
		(*stack_a) = aux -> next;
	}
}
