/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mininhead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:48:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/12 20:03:49 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	minelem(t_stack *stacka)
{
	t_stack	*temp;
	int		min;

	temp = stacka;
	min = temp ->content;
	while (1)
	{
		if (temp -> content < min)
			min = temp -> content;
		temp = temp -> next;
		if (temp == stacka)
			break ;
	}
	return (min);
}
