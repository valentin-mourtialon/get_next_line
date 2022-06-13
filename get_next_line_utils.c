/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:20:47 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/13 11:25:35 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

t_list	*lst_new(char c)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->character = c;
	new->next = NULL;
	return (new);
}

list_start	*init_queue(void)
{
	list_start	*start;

	start = malloc(sizeof(list_start));
	if (!start)
		return (NULL);
	start->first = lst_new(0);
	return (start);
}

t_list	*lst_last_element(list_start *start)
{
	t_list	*last;

	if (!start)
		return (NULL);
	last = start->first;
    if (!last)
        return (NULL);
    else
    {
        while (last->next != NULL)
            last = last->next;
        return (last);
    }
}

void	lst_delete_one(list_start *start)
{
	t_list	*first_element;

	first_element = start->first;
	start->first = start->first->next;
	free(first_element);
}