/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:10:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/18 18:25:47 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct s_stack
{
	int				content;
	int				nbmvmnt;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ij
{
	int	i;
	int	j;
}	t_ij;

void		ft_putstr(char *str);
void		error(void);
int			ft_isdigit(int c);
int			ft_strlen(const char *s);
size_t		ft_strlen2(const char *s);
void		error(void);
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
int			*largest(t_stack *stack_a, int ac, int *num);
void		pushtop(t_stack **stack_b, t_stack **stack_a,
				int *tab, t_ij len_ac);
int			lenstack(t_stack *temp);
void		pushtop(t_stack **stack_b, t_stack **stack_a,
				int *tab, t_ij len_ac);
void		pushtoa(t_stack **stacka, t_stack **stackb);
int			lenstack(t_stack *temp);
void		push_elem_in_head(t_stack **stack, int val, char ab);
char		*ft_strjoin(int size, char **strs, char *sep);
int			minelem(t_stack *stacka);
int			*largest2(t_stack *stack_a, int ac, int *num);
char		**convert(int *ac, char **av);
int			minmvmnt(t_stack *lst);
char		**ft_split(char const *s, char c);
int			ft_numofsplit(const char *s, char spl);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			count_to_head(t_stack *tmp, int elem, int *rvrt, char ab);
void		reversrot(t_stack **stack_a, t_stack **stack_b, t_ij temp, t_ij rv);
int			right_number(t_stack *temp, int num);
void		simple_sort(t_stack **stacka, t_stack **stackb);
int			ft_strncmp(const char *s1, const char *s2);
void		ft_free(char **spl);
#endif