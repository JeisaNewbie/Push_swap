/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:49:06 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 04:31:57 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*before;
	long			data;
	int				check_dummy;
	int				flag;
}	t_node;

typedef struct s_list
{
	t_node			*head;
	t_node			*cur;
	int				numofdata;
	int				start;
	char			*content;
	struct s_list	*next;
	int				fd;
}	t_list;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		**arr;
	int		*idx;
	int		depth;
	int		num_of_tri;
	int		start;
	int		to_a;
}	t_swap;

int		check_error(int argc, char **argv, int i, int flag);
int		check_reduplication(long *arr, int length);
int		check_sorted(long *arr, int length, int flag);
t_list	*init_stack(int flag);
int		*create_idx(void);
int		**create_arr(int n);
t_swap	*init_swap(int argc, int flag);
int		check_pow(int i);
void	check_ascending(int **arr, int *idx);
void	divide(int argc, int **arr, int *idx, int depth);
void	check_tri(int argc, int i, int *depth);
int		check_struct(t_swap *swap, int argc, int *depth);
void	print_error(void);
void	free_argv(char **argv);
void	free_stack(t_swap *swap);
void	free_all(char **argv, t_swap *swap);
long	ft_atoi(const char *string, long minus, int i);
char	*ft_strdup(const char *s1);
long	check_string(char *str, long minus);
void	list_insert(t_list *list, long data);
void	list_remove(t_node *node);
long	list_first(t_list *list);
long	list_last(t_list *list);
long	list_next(t_list *list);
long	list_previous(t_list *list);
int		swap_a(t_node *dummy);
int		swap_b(t_node *dummy);
int		ss(t_node *dummy_a, t_node *dummy_b);
int		push_a(t_list *stack_a, t_list *stack_b);
int		push_b(t_list *stack_b, t_list *stack_a);
int		rotate_a(t_list *stack);
int		rotate_b(t_list *stack);
int		rr(t_list *stack_a, t_list *stack_b);
void	double_pa(t_swap *swap);
void	double_pb(t_swap *swap);
int		reverse_ra(t_list *stack);
int		reverse_rb(t_list *stack);
int		reverse_rr(t_list *stack_a, t_list *stack_b);
void	double_rra(t_swap *swap);
void	double_rrb(t_swap *swap);
int		check_number(char *argv, int check_num);
int		count_number(char *argv);
char	**init_input(int *argc, char **argv);
char	**remake_input(char **argv, int count);
int		ft_split_p(char **input, char *argv, int *i);
int		ft_strchr_s(char *s, int c);
char	*ft_strdup_s(char *s1, int *idx);
int		do_command(t_swap *swap);
int		check_command(t_swap *swap, char *command, int length);
int		check_stack_sorted(t_swap *swap);
int		ft_strncmp_p(char *s1, char *s2, size_t n);
t_list	*lstnew(int fd);
void	lstfree(t_list **backup);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_split(t_list **backup);
char	*read_fd(int fd, t_list **backup);
int		ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif