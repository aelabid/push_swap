/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:28:05 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/10 12:47:01 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	ifintab(int *tab, int val, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == val)
			return(1);
		i++;
	}
	return(0);
}

int	counttohead(t_stack *stack, int elem)
{
	t_stack *temp;
	int		i;
	int		len;

	len = lenstack(stack);
	i = 0;
	temp = stack;
	while (temp->content != elem)
	{
		i++;
		temp = temp -> next;
	}
	if (i - 1 > (len) / 2)
	{
		// *bl = 0;
		return (len - i);
	}
	// *bl = 1;
	return (i);
}

void	pushnbmvnt(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (1)
	{
		temp->nbmvmnt = counttohead(*stack, temp->content);
		temp = temp -> next;
		if (temp == *stack)
			break ;
	}
}

void	push_elem_in_head(t_stack **stack, int val, char ab)
{
	t_stack	*temp;
	int	i;
	int bl;
	int	len;

	len = lenstack(*stack);
	
	i = 0;
	temp = *stack;
	while ((temp) -> content != val)
	{
		temp = temp->next;
		i++;
	}
	if (i > (len) / 2)
		bl = 0;
	else
		bl = 1;
	while (temp != *stack)
	{
		if (bl == 1)
			rotate(stack, ab);
		else
			revrot(stack, ab);
	}
}

int	minmvmnt2(t_stack *lst, int *tab, t_ij len_ac)
{
	int	min;
	int	minval;
	t_stack	*temp;
	
	temp = lst;
	min = 1000;
	while (1)
	{		
		 if (temp->nbmvmnt <= min && ((ifintab(tab, (temp) -> content, len_ac.i) == 0)))
			minval = temp->content;
		temp = temp -> next;
		if (lst == temp)
			break ;
	}
	
	return(minval);
}
int	*checkiflarge(t_stack *stack_a, t_ij len_ac, int *tall)
{
	int	*tab;
	
	// int	tall;
	int i = 0;
	tab = largest2(stack_a, len_ac.j, tall);
	// printf("---------tall = %d\n", *tall);
	// while(i < *tall)
	// {
	// 	printf("%d\t", tab[i]);
	// 	i++;
	// }
	if (*tall > len_ac.i)
		return (tab);
	// printf("----------------not tall = %d\n", *tall);
	return (NULL);
}

void    pushtop(t_stack **stack_b,  t_stack **stack_a, int *tab, t_ij len_ac)
{
	t_stack	*temp;
	int	*temptab;
	int len;
	int i = 0;
	int j = 0;
	int tall;
	temp = *stack_a;
	pushnbmvnt(stack_a);
	minmvmnt(*stack_a);
	// printf("this is the number = %d \n", (*stack_a)->content);
	// while(1)
	// {
	// 	printf("num is = %d\tnb mvmnt = %d\n", temp->content,temp->nbmvmnt);
	// 	temp = temp->next;
	// 	if (temp == *stack_a)
	// 	break;
	// }
	len = len_ac.j - len_ac.i -1 ;
	printf("len is = %d\n", len);
	while (len > 0)
	{
		if ((ifintab(tab, (temp) -> content, len_ac.i) == 0) && (temp -> content == minmvmnt2(*stack_a, tab, len_ac)))
		{
			push_elem_in_head(stack_a, (temp) -> content, 'a');
			push(stack_a, stack_b, 'b');
			len--;
			j++;
			temptab = checkiflarge(*stack_a, len_ac,&tall);
			if (tall > len_ac.i)
			{
			// 	// printf("hellloooo");
			// 	i = 0;
			len_ac.i = tall;
				
			tab = temptab;
				i = 0;
				// while(i < tall)
				// {
				// 	printf("%d\t", tab[i]);
				// 	i++;
				// }
			// // // 	printf("-----------hello-------------\tlen = %d\n", len);
				
			// // // 	tab = checkiflarge(*stack_a, len_ac);
			// // // 	printf("\nlen = %d\n", len_ac.i);
			// // 	// while(i < tall)
			// // 	// {
			// // 	// 	printf("%d\t", tab[i]);
			// // 	// 	i++;
			// // 	// }
			// // // 	printf("\n\n");
			len = len_ac.j - len_ac.i - 1 - j;
			}
			pushnbmvnt(stack_a);
			temp = *stack_a;
		}
		else
		{
			temp = temp -> next;
		}
	}
}
