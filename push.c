/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:34:42 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/05 16:45:02 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	push(t_stack **stack_a, t_stack **stack_b, char ab)
{
	t_stack *aux;
	t_stack	*temp;
	
	if (*stack_a != NULL)
	{
		if (ab == 'b')
			printf("pb\n");
		else if (ab == 'a')
		 	printf("pa\n");
		if (*stack_b == NULL)
			*stack_b = ft_lstnew((*stack_a) -> content);
		else
		{
			temp = ft_lstnew((*stack_a)->content);
			temp -> next = *stack_b;
			ft_lstlast(*stack_b) -> next = temp;
			*stack_b = temp;
		}
		aux = ft_lstlast(*stack_a);
		if (aux->next == aux)
		{
			(*stack_a) = NULL;
			return ;
		}
		aux -> next = (*stack_a) -> next;
		free(*stack_a);
		(*stack_a) = aux -> next;
	}
}

