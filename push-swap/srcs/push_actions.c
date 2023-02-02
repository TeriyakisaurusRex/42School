#include "push_swap.h"

static void push(t_stack **origin, t_stack **dest)
{
    t_stack *temp;

    if (*origin == NULL)
        return;
    temp = (*origin)->next;
    (*origin)->next = *next;
    *dest = *origin;
    *origin = temp;
}

void pa(t_stack **stacka, t_stack **stackb)
{
    push(stackb, stacka);
    write(1, "pa\n", 3);
}

void pb(t_stack **stacka, t_stack **stackb)
{
    push(stacka, stackb);
    write(1, "pb\n", 3);
}