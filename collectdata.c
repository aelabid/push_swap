/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:49:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/02 12:28:22 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"


// t_stack	*ft_lstnew(int content)
// {
// 	t_stack	*new;

// 	new = (t_stack *) malloc(sizeof(t_stack));
// 	if (!new)
// 		return (NULL);
// 	new -> content = content;
// 	new -> next = NULL;
// 	return (new);
// }

// void	ft_lstadd_front(t_stack **alst, t_stack *new)
// {
// 	new -> next = *alst;
// 	*alst = new;
// }

t_stack	*fillstack(char **av)
{
	int		i;
	t_stack	*data;

	i = 2;
	data = ft_lstnew(ft_atoi(av[1]));
	while (av[i])
	{
		ft_lstadd_front(&data, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (data);
}