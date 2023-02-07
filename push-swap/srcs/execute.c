#include "../include/push_swap.h"

static void rotate_stacks(t_stack **a, t_stack **b, int *costa, int *costb);
static void rev_rotate_stacks(t_stack **a, t_stack **b, int *costa, int *costb);
static void rotate_a(t_stack **a, int *costa);
static void rotate_b(t_stack **b, int *costb);

void exe_move(t_stack **a, t_stack **b, int costa, int costb)
{
    if (costa < 0 && costb < 0)
        rev_rotate_stacks(a, b, &costa, &costb);
    else if (costa > 0 && costb > 0)
        rotate_stacks(a, b, &costa, &costb);
    rotate_a(a, &costa);
    rotate_b(b, &costb);
    pa(a, b);
}

static void rotate_stacks(t_stack ** a, t_stack ** b, int * costa, int * costb)
{
    while(*costa > 0 && costb > 0)
    {
        (*costa)--;
        (*costb)--;
        rr(a, b);
    }
}

static void rev_rotate_stacks(t_stack ** a, t_stack ** b, int * costa, int * costb)
{
    while(*costa < 0 && costb < 0)
    {
        (*costa)++;
        (*costb)++;
        rrr(a, b);
    }
}

static void rotate_a(t_stack **a, int *cost)
{
    while (*cost)
    {
        if(*cost > 0)
        {
            ra(a);
            (*cost)--;
        }
        else if(*cost < 0)
        {
            rra(a);
            (*cost)++;
        }
    }
}

static void rotate_b(t_stack **b, int *cost)
{
    while(*cost)
    {
        if (*cost > 0)
        {
            rb(b);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rrb(b);
            (*cost)++;
        }
    }
}