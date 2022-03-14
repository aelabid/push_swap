/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:49:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/12 19:59:31 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

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
