#include "push_swap.h"

void move_cost(t_stack **stacka, t_stack ** stackb)
{
    t_stack *tempa;
    t_stack *tempb;
    int sizea;
    int sizeb;

    tempa = *stacka;
    tempb = *stackb;
    sizea = get_stack_size(tempa);
    sizeb = get_stack_size(tempb);
    while(tempb)
    {
        tempb->cost_b = tempb->pos;
        if (tempb->pos > sizeb / 2)
            tempb->cost_b = (sizeb - tempb->pos) * -1;
        tempb->cost_a = tempb->target_pos;
        if (tempb->target_pos > sizea / 2)
            tempb->cost_a = (sizea - tempb->target_pos) * -1;
        tempb = tempb->next;
    }
}

int absolute(int num)
{
    if (num < 0)
        return (num * -1);
    return (num);
}

void exe_lowcost(t_stack **stacka, t_stack **stackb)
{
    t_stack *temp;
    int lowcost;
    int costa;
    int costb;

    temp = *stackb;
    lowcost = INT_MAX;
    while (temp)
    {
        if (absolute(temp->cost_a) + absolute(temp-cost_b) < absolute(lowcost))
        {
            lowcost = absolute(temp->cost_b) + absolute (temp->cost_a);
            cost_a = temp->cost_a;
            cost_b = temp->cost_b;
        }
        temp = temp->next;
    }
    exe_move(stacka, stackb, costa, costb);
}