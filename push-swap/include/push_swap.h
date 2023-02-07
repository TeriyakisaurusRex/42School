#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h> //?
#include <stdlib.h> //for exit

//# define DEFINE 0
//# define MAX_INT 0
//# define MIN_INT -0

typedef struct s_stack
{
    int value;      // numerical value, given integer
    int index;      // index in the list of all values
    int pos;        // current position in stack
    int target_pos; // where it wants to go 
    int costa;     // how many actions it would take it to get to the top of stack a
    int costb;     // how many actions it would take it to get to the top of stack b
    struct s_stack *next;  // next struct
}   t_stack;


int			check_input(char **argv);

void		move_cost(t_stack **stacka, t_stack **stackb);
int			absolute(int num);
void		exe_lowcost(t_stack **stacka, t_stack **stackb);

void		exe_move(t_stack **a, t_stack **b, int costa, int costb);

t_stack		*init_stack(int argc, char **argv);
t_stack		*add_node(int num);
void		add_to_bottom(t_stack **stack, t_stack *num);
int			get_stack_size(t_stack *stack);
void		init_index(t_stack *stacka, int size);

void		init_tp(t_stack **stacka, t_stack **stackb);
int			lowest_index(t_stack **stack);

void		pa(t_stack **stacka, t_stack **stackb);
void		pb(t_stack **stacka, t_stack **stackb);

int			sorted(t_stack *stack);

void		rra(t_stack **stacka);
void		rrb(t_stack **stackb);
void		rrr(t_stack **stacka, t_stack **stackb);

void		ra(t_stack **stacka);
void		rb(t_stack **stackb);
void		rr(t_stack **stacka, t_stack **stackb);
t_stack		*get_end(t_stack *stack);

void		sort(t_stack **stacka, t_stack **stackb);
void		hold_three(t_stack **stacka, t_stack **stackb);
void		sort_three(t_stack **stack);

void		sa(t_stack **stacka);
void		sb(t_stack **stacka);
void		ss(t_stack **stacka, t_stack **stackb);

long		ft_atoi(const char *str);

/*
typedef struct s_structname
{
    void *anypointer;
    char value;
    int value;
} t_structname
*/

// file1 prototypes
// int function_that_is_used_across_file (type value);

#endif
