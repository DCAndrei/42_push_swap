/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:15:09 by acretu            #+#    #+#             */
/*   Updated: 2022/01/26 16:55:17 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

//list_utils.c

t_list	*ft_lstnew(int n);
int		ft_add_elem(t_list **lst, t_list *elem);
int		ft_del_elem(t_list **lst);
int		ft_list_size(t_list *lst);

//moves_utils_a

void	ft_sa_move(t_list **lst);
void	ft_ra_move(t_list **start);
void	ft_rra_move(t_list **start);
void	ft_push_b(t_list **a, t_list **b);
void	ft_rr_move(t_list **a, t_list **b);

//moves_utils_b

void	ft_sb_move(t_list **lst);
void	ft_rb_move(t_list **start);
void	ft_rrb_move(t_list **start);
void	ft_push_a(t_list **a, t_list **b);
void	ft_rrr_move(t_list **a, t_list **b);

//ft_small_sort

void	ft_small_sort(t_list **lst);
void	ft_help_small_sort(t_list **lst);
t_list	*ft_find_min(t_list *lst);
int		ft_get_position(t_list *lst);
int		ft_check(t_list *lst);

//small_sort_utils

t_list	*ft_find_max(t_list *lst);
void	ft_small_sort_reverse(t_list **lst);
void	ft_help_small_sort_reverse(t_list **lst);
int		ft_get_position_max(t_list *lst);
int		ft_check_reverse(t_list *lst);

//sorting_utils

void	ft_move_to_b(t_list **a, t_list **b, int moves);
void	ft_go_to_min(t_list **lst);

int		ft_check_input(int argc, char *argv[]);
int		ft_initial_check(char *str);
int		ft_second_check(t_list **lst);
int		ft_check_int(char *str);

t_list	*ft_init_stack(int argc, char *argv[]);

int		ft_atoi(char *str);

// sorting_in_order

int		ft_order(t_list	**lst);
int		*ft_create_array(t_list	**lst, int *size);
void	ft_bubble_sort(int *array, int size);
void	ft_swap(int *a, int *b);

// ft_large_sort.c

void	ft_maxi_sort(t_list **lst);
void	ft_handle_b_stack_min(t_list **b, t_list **lst);
void	ft_handle_b_stack_max(t_list **b, t_list **lst);
void	ft_large_sort(t_list **lst, t_list **b, int **pivots, \
		int **total_elem_b);
void	ft_help_stack_min(int *position, int *pushed, \
		t_list **lst, t_list **b);

//large_sort_utils_one

int		ft_sb(t_list **lst, t_list **b, int pivot, int total);
void	ft_iteration(t_list **lst, t_list **b, int piv1, int piv0);
int		ft_f_b_p(t_list **lst, t_list **b, int pivot, int total);
void	ft_move_b_to_a(t_list **lst, t_list **b, int pivot);
void	ft_init_array(t_list **lst, int *size, int **array);

//large_sort_utils_two

int		ft_pushb(t_list **lst, t_list **b, int pivot, int elem_b);
void	ft_create_pivots_array(int size, int **pivots, int **total_elem_b, \
		int *nr_pivots);
void	ft_complete_pivots(int *array, int **pivots, int size, int nr_pivots);
void	ft_complete_total_elem(int **total, int nr_pivots, int size);
void	ft_last_push_b(t_list **lst, t_list **b, int min);

//large_sort_utils_three

int		ft_nr_moves(t_list *b);
int		ft_help_nr_moves(t_list *b, int **moves, int **list, int nr_elem);
void	ft_complete_moves(int *moves, int *list, int size);
void	ft_complete_moves_max(int *moves, int *list, int size);
void	ft_add_to_array(int *array, int size, int position, int value);

//large_sort_utils_four

int		ft_nr_moves_last(t_list *b);
int		ft_help_nr_moves_last(t_list *b, int **moves, int **list, int nr_elem);
void	ft_help_last_push(t_list **l, t_list **b, int min, int count);

#endif
