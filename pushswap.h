/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:10:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/08 16:04:02 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include<stdio.h>
#include<stdlib.h>

typedef struct s_stack
{
	int		content;
	int		nbmvmnt;
	struct s_stack	*next;
} t_stack;

typedef struct s_ij
{
	int	i;
	int	j;
} t_ij;

typedef struct s_reteb
{
	int	content;
	int	nbmvmn;
	struct s_reteb *next;	
} t_reteb;

void		error();
int			ft_isdigit(int c);
int			ft_strlen(const char *s);
long long	ft_atoi(const char *c);
void		checkalpha(char **av);
void		checkdouble(int ac, char **av);
void		checkmaxint(char **av);
t_stack		*fillstack(char **av);
void		swap(t_stack *stack, char ab);
void		push(t_stack **stack_a, t_stack **stack_b, char ab);
void		swap2(t_stack *stack1, t_stack *stack2);
void		swap3(t_stack *stack);
void		ft_lstadd_front(t_stack **alst, t_stack *new);
t_stack		*ft_lstnew(int content);
void		ft_lstadd_back(t_stack **alst, t_stack *new);
void		rotate(t_stack **stack, char c);
void		rotate2(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_lstlast(t_stack *lst);
void		revrot(t_stack **stack, char c);
void		revrot2(t_stack **stack_a, t_stack **stack_b);
int			*largest(t_stack *stack_a , int ac, int *num);
void    	pushtop(t_stack **stack_b,  t_stack **stack_a, int *tab, t_ij len_ac);
t_reteb		*lstnew_reteb(int content, int nbmvm);
void		add_front_reteb(t_reteb **lst, t_reteb *new);
int			lenstack(t_stack *temp);
void    	pushtop(t_stack **stack_b,  t_stack **stack_a, int *tab, t_ij len_ac);
void		pushtoa(t_stack **stacka, t_stack **stackb);
int			lenstack(t_stack *temp);
void		push_elem_in_head(t_stack **stack, int val, char ab);
int			minelem(t_stack *stacka);
int			*largest2(t_stack *stack_a, int ac, int *num);
int			minmvmnt(t_stack *lst);
#endif