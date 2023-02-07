/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:29:50 by jthiele           #+#    #+#             */
/*   Updated: 2023/02/07 15:30:49 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	if (*origin == NULL)
		return ;
	temp = (*origin)->next;
	(*origin)->next = *dest;
	*dest = *origin;
	*origin = temp;
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	push(stackb, stacka);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	push(stacka, stackb);
	write(1, "pb\n", 3);
}
