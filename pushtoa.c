/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:32:55 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/10 14:25:53 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	lenstack(t_stack *temp)
{
	t_stack	*tmp;
	int		i;
	
	i = 0;
	tmp = temp;
	while (1)
	{
		i++;
		tmp = tmp -> next;
		if (tmp == temp)
			break ;
	}
	return (i);
}


int	bigelem(t_stack *temp)
{
	t_stack	*tmp;
	int		big;
	
	tmp = temp;
	big = temp -> content;
	while (1)
	{
		if (tmp -> content > big)
			big = tmp -> content;
		tmp = tmp -> next;
		if (temp == tmp)
			break ;
	}
	return (big);
}

int	right_number(t_stack *temp, int num)
{
	t_stack	*tmp;
	int	big;
	
	tmp = temp;
	big = bigelem(tmp);
	while (1)
	{
		if ((tmp->content > num) && (tmp->content < big))
		{
			big = tmp -> content;
		}
		tmp = tmp -> next;
		if (temp == tmp)
			break;
	}
	return (big);
}

// int	count_from_b_to_head(t_stack *temp, int elem, int *revrot)
// {
// 	int	i;
// 	int	len;

// 	len = lenstack(temp);
// 	i = 0;
// 	while (temp -> content != elem)
// 	{
// 		temp = temp -> next;
// 		i++;
// 	}
// 	if (i > (len / 2))
// 	{
// 		*revrot = 0;
// 		return (len - i);
// 	}
// 	*revrot = 1;
// 	return (i);
// }

// int	count_from_head_to_a(t_stack *stack_a, int elem, int *rvrt)
// {
// 	t_stack	*temp;
// 	int	i;
// 	int	len;

// 	len = lenstack(stack_a);
// 	i = 0;
// 	temp = stack_a;
// 	while (temp -> content != right_number(temp, elem))
// 	{
// 		i++;
// 		temp = temp -> next;
// 		if (temp == stack_a)
// 			break;
// 	}
// 	if (i > len / 2)
// 	{
// 		*rvrt = 0;
// 		return (len - i);
// 	}
// 	*rvrt = 1;
// 	return (i);
// }

int	count_to_head(t_stack *tmp, int elem, int *rvrt, char ab)
{
	int	i;
	int	len;
	int element;
	t_stack *temp;

	temp = tmp;
	if (ab == 'b')
		element = elem;
	else
		element = right_number(temp, elem);
	len = lenstack(tmp);
	i = 0;
	while (temp -> content != element)
	{
		i++;
		temp = temp -> next;
	}
	
	if (i-1 > len / 2)
	{
		*rvrt = 0;
		return (len - i);
	}
	*rvrt = 1;
	return (i);
}



void	push_right_element(t_stack **stack_a, t_stack **stack_b, int tempa, int tempb)
{
	t_stack	*tempsa;
	t_stack	*tempsb;
	int		rvrta;
	int		rvrtb;
	int var= 0;
	
	tempsa = *stack_a;
	tempsb = *stack_b;
	count_to_head(tempsb, tempb, &rvrtb, 'b');
	count_to_head(tempsa, tempb, &rvrta, 'a');
	while ((tempb != (*stack_b) -> content) && (tempa != (*stack_a) -> content) && var == 0)
	{
		if ((rvrta == 0 && rvrtb == 0) || (rvrta == 1 && rvrtb == 1))
		{
			if (rvrta == 0 && rvrtb == 0)
				revrot2(stack_a, stack_b);
			else if (rvrta == 1 && rvrtb == 1)
				rotate2(stack_a, stack_b);
		}
		else
			var = 1;
	}
	while (tempa != (*stack_a) -> content)
	{
		if (rvrta == 0)
			 revrot(stack_a, 'a');
		else
			rotate(stack_a, 'a');
		// *stack_a = (*stack_a)->next;
	}
	while (tempb != (*stack_b) -> content)
	{
		if (rvrtb == 0)
			revrot(stack_b, 'b');
		else
			rotate(stack_b, 'b');
		// *stack_b = (*stack_b)->next;
	}
	push(stack_b, stack_a, 'a');
}

int	minmvmnt(t_stack *lst)
{
	int	min;
	int	minval;
	t_stack	*temp;
	
	temp = lst;
	min = temp -> nbmvmnt;
	while (1)
	{		
		 if (temp->nbmvmnt <= min)
			minval = temp->content;
		temp = temp -> next;
		if (lst == temp)
			break ;
	}
	// printf()
	return(minval);
}

void	pushnbmvmnt(t_stack *stackb, t_stack *stacka)
{
	int	nbmva;
	int	nbmvb;
	int	bmna;
	int	bmnb;
	t_stack *temp;

	temp = stackb;
	while (1)
	{
		nbmvb = count_to_head(stackb, temp -> content, &bmnb, 'b');
		nbmva = count_to_head(stacka, temp -> content, &bmna, 'a');
		if ((bmna == 0 && bmnb == 0) || (bmna == 1 && bmnb == 1))
		{
			if(nbmva > nbmvb)
				temp->nbmvmnt = nbmva;
			else
				temp->nbmvmnt = nbmvb;
		}		
		else
			temp->nbmvmnt = nbmva + nbmvb;
		temp = temp -> next;
		if (temp == stackb)
			break;
	}
}

void	pushtoa(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_reteb	*lst = NULL;
	int	nbmvb;
	int	nbmva;
	int	bmna;
	int	min;
	int	right;
	
	temp = *stackb;
	
	pushnbmvmnt(*stackb, *stacka);
	temp2 = *stackb;
	// while(1)
	// {
	// 	printf("number is : %d\tand num mvmnt = %d\n", temp2->content, temp2->nbmvmnt);
	// 	temp2 = temp2->next;
	// 	if(temp2 == *stackb)
	// 		break;
	// }
	// printf("*----------------------------*");
	while (*stackb != NULL)
	{
		if (temp -> content == minmvmnt(*stackb))
		{
			// printf("content = %d\t, nbmvmtn = %d\n", temp->content, temp->nbmvmnt);
			push_right_element(stacka, stackb, right_number(*stacka, temp->content), temp->content);
			temp = *stackb;
			if(*stackb != NULL)
			{
				pushnbmvmnt(*stackb, *stacka);
				// printf("element =%d\t nbmouvement = %d\n",temp->content, temp->nbmvmnt);
			}
		}
		else
			temp = temp -> next;
	}
}
