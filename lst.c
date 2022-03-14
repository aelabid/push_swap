/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:11:41 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/12 20:03:09 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	t_stack	*temp;

	new -> next = *alst;
	temp = ft_lstlast(*alst);
	temp -> next = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = new;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (lst == 0)
		return (0);
	tmp = lst;
	while (lst->next != tmp)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*temp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	temp = ft_lstlast(*alst);
	temp->next = new;
}
