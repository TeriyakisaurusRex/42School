#include "../include/push_swap.h"

t_stack *second_last(t_stack *stack);

static void rev_rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *end;
    t_stack *sec_last;

    end = get_end(*stack);
    sec_last = second_last(*stack);
    temp = *stack;
    *stack = end;
    (*stack)->next = temp;
    sec_last->next = NULL;
}

void rra(t_stack **stacka)
{
    rev_rotate(stacka);
    write(1, "rra\n", 4);
}

void rrb(t_stack **stackb)
{
    rev_rotate(stackb);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **stacka, t_stack **stackb)
{
    rev_rotate(stacka);
    rev_rotate(stackb);
    write(1, "rrr\n", 4);
}

t_stack *second_last(t_stack *stack)
{
    while (stack->next->next)
        stack = stack->next;
        return (stack);
}