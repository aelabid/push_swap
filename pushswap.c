/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:50 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/14 12:54:55 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av = convert(&ac, av);
		if (ac == 1)
			return (0);
		checkalpha(av);
		checkdouble(ac, av);
		checkmaxint(av);
		t_stack *stacka;
		t_stack *stackb;
		t_ij	len_ac;
		len_ac.i = 0;
		len_ac.j = ac;
		int	i = 0;
		//int	num;
		
		stacka = fillstack(av);
		int k = 0;
		// int *tab;
		
		// stacka.content = 1;
		//largest(stacka, ac, &num);
		int *tab = largest2(stacka, ac, &len_ac.i);
		
		if (len_ac.i == ac - 1)
		{
			push_elem_in_head(&stacka, minelem(stacka), 'a');
			return(0);
		}
		pushtop(&stackb, &stacka, tab, len_ac);
		// void	pushtop(t_stack **stack_b,  t_stack **stack_a, int *tab, t_ij len_ac);
		pushtoa(&stacka, &stackb);
		push_elem_in_head(&stacka, minelem(stacka), 'a');
		//test(&stacka, tab, num);
		// int arr[]= {1, 5 ,7, 8, 5 , 7};
		// // printf("%lu", sizeof(arr));
		// while(i < len_ac.i)
		// {
		// 	printf("%d\t", tab[i]);
		// 	//printf("\n%p\n", &tab[i]);
		// 	i++;
		// }
		
		//largest(stacka, ac);
		// while (k < len_ac.i)
		// {
		// 	printf("%d\t", tab[k]);
		// 	k++;
		// }
		//stackb = fillstack(av);
		//push(&stacka, &stackb, 'b');
		//swap(stacka, 'a');
		// push(&stacka, &stackb, 'b');
		// push(&stacka, &stackb, 'b');
		// push(&stackb, &stacka, 'a');
		// push(&stackb, &stacka, 'a');
		//revrot(&stacka, 'a');
		// while(1) ;
		// printf("\n");
		//  printf("\n");
		// printf("\n");
		t_stack *temp;
		 temp = stacka;
		// // printf("\n");
		// // printf("\n");
		// while (1)
		// {
		// 	printf("%d\t",stacka -> content);
		// 	stacka = stacka -> next;
		// 	if (stacka == temp)
		// 		break;
		// }
		// // printf("\n");
		// // printf("\n");
		// printf("\n");
		// printf("\n");
		// printf("\n");
		// // stackb->content = 1;
		// // stackb -> next = stackb;
		// temp = stackb;
		// while (stackb != NULL)
		// {
		// 	printf("%d\t",stackb -> content);
		// 	stackb = stackb -> next;
		// 	if (stackb == temp)
		// 		break;
		// }
		// swap2(stacka, stackb);
		// swap(stackb, 'b');
		//rotate2(&stacka,&stackb);
		// revrot2(&stacka, &stackb);
		// while (stacka != NULL)
		// {
		// 	printf("%d\t",stacka -> content);
		// 	stacka = stacka -> next;
		// }
		// printf("\n");
		// while (stackb != NULL)
		// {
		// 	printf("%d\t",stackb -> content);
		// 	stackb = stackb -> next;
		// }
		
	}
}