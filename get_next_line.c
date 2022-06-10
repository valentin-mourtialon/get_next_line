/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:50:38 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/10 17:05:54 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


t_list	*lst_new(char c)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->character = c;
	lst->next = NULL;
	return (lst);
}

start_list	*init_queue(void)
{
	start_list	*start;

	start = malloc(sizeof(start_list));
	if (!start)
		return (NULL);
	start->ptr = lst_new(0);
	return (start);
}

void	add_each_char_to_queue(char *src, t_list *queue)
{
	while (*src)
	{
		queue->character = *src++;
		queue->next = lst_new(*src);
		queue = queue->next;
	}
	queue->next = lst_new(0);
	queue = queue->next;
}

void	display_queue(t_list *queue_start)
{
	t_list	*queue;
	char	c;

	queue = queue_start->next;
	while (queue->character != '\n')
	{
		c = queue->character;
		write(1, &c, 1);
		//del le character !
		queue = queue->next;
	}
}

int	a_line_is_found(t_list *queue_start)
{
	t_list	*queue;
	char	c;

	queue = queue_start->next;
	while (queue->next != NULL)
	{
		c = queue->character;
		write(1, &c,1);
		if  (queue->character == '\n')
			return (1);
		queue = queue->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	start_list	*start;
	t_list		*queue;
	int			nbytes;
	
	start = init_queue();
	//queue = start->next;
	nbytes = 1;
	while (!a_line_is_found(start) && nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		add_each_char_to_queue(buffer, queue);
		write(1, "\n", 1);
	}
	display_queue(queue_start);
	return (buffer);
}

int	main(void)
{
	int		fd;

	fd = open("testfiles/test5.txt", O_RDONLY);
	get_next_line(fd);
	//get_next_line(fd);
	return (0);
}