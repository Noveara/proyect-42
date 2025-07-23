/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:50:21 by mokhan            #+#    #+#             */
/*   Updated: 2025/07/23 18:32:30 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <math.h>
# include <limits.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				i;
	int				num;
	struct s_stack	*nxt;
	struct s_stack	*last;
}	t_stack;

typedef struct s_step
{
	int	a;
	int	b;
	int	rot;
	int	least;
}	t_step;

typedef struct s_data
{
	int		size;
	int		flg;
	int		chker;
	t_stack	*a;
	t_stack	*b;
	t_step	mini;
}	t_data;

typedef struct s_count
{
	int	a;
	int	rb;
	int	rrb;
}	t_count;

int		is_sorted(t_stack *a);
void	print_res(t_data *d);
void	ps(t_data *d, char *cmd);
void	get_input(t_data *d);
int		main(int argc, char **argv);
void	cmd_rot(t_data *d, char *c);
void	cmd_sp(t_data *d, char *c);
int		is_numeric(const char *str);
int		indexing(int num, int *n, int size);
int		validate(int i, char **av);
t_stack	*init_list(t_data *d, t_stack *a, int *num);
t_stack	*init_stack(t_data *d, int size, char **av, int add);
int		ps_lstmin(t_stack *lst);
int		ps_lstmax(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);
t_stack	*ps_lstnew(int n, int i);
int		ps_lstsize(t_stack *lst);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
void	ps_lstclear(t_stack **head);
void	ps_swap(t_stack **stack);
void	ps_push(t_stack **a, t_stack **b);
void	ps_rotate(t_stack **stack);
void	ps_rrotate(t_stack **stack);
void	case1(t_data *d, t_step s);
void	case2(t_data *d, t_step s);
void	case3(t_data *d, t_step s);
void	case4(t_data *d, t_step s);
void	rotate_sort(t_data *d, t_step s);
t_step	ps_least(t_data *d, int a, int b, t_step cur);
t_step	ps_least2(t_data *d, int a, int b, t_step cur);
int		max_stack(int max, t_stack *a);
void	move_half(t_data *d);
void	pushb(t_data *d);
void	pusha(t_data *d);
void	sort3(t_data *d);
void	sort5(t_data *d, t_stack *min);
int		steps_to_min(t_stack *a);
void	do_sort(t_data *d);
int		insert_steps(int val, t_stack *tmp_a);
int		target_steps(int val, t_stack *a);
t_step	optimal_steps(t_data *d, int b_steps, t_stack *tmp_b);
void	evaluate_steps(t_data *d, int max);
void	ft_error(void);
void	ft_free(void **ptr);
int		ps_strcmp(const char *s1, const char *s2, size_t n);
long	atoi_long(const char *nptr);
int		is_sorted(t_stack *a);
int		main(int argc, char **argv);
int		is_sorted(t_stack *stack);
int		rotations(t_data *d, t_stack *min);
t_stack	*get_ptr_min(t_stack *a, int opc);

#endif