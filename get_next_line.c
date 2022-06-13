/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:40:56 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/13 11:46:59 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_each_char_to_queue(char *src, list_start *start, int nbytes)
{
	t_list	*last;
	int		i;

	last = lst_last_element(start);
	i = 0;
	while (i < nbytes)
	{
		last->next = lst_new(src[i++]);
		last = last->next;
	}
}

int	a_line_is_found(list_start *start)
{
	t_list	*ptr;

	ptr = start->first;
	while (ptr->next != NULL)
	{
		if  (ptr->character == '\n')
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	display_queue(list_start *start)
{
	t_list	*ptr;

	ptr = start->first;
	while (ptr->character != '\n' && ptr->next != NULL)
	{
		ft_putchar_fd(ptr->character, 1);
		ptr = ptr->next;
		lst_delete_one(start);
	}
	ft_putchar_fd(ptr->character, 1);
	lst_delete_one(start);
}

int	queue_is_empty(list_start *start)
{
	t_list	*ptr;

	ptr = start->first;
	if (ptr == NULL)
	{
		//free(ptr);
		//free(start);
		return (1);
	}
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE];
	static list_start	*start;
	static int			n_calls = 0;
	int					nbytes;
	
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}

	if (n_calls == 0)
		start = init_queue();
	n_calls++;

	nbytes = read(fd, buffer, BUFFER_SIZE);
	
	if (buffer == NULL || (nbytes == 0 && queue_is_empty(start)))
	{	
		//free(start);
		return (NULL);
	}
	while (nbytes == BUFFER_SIZE && !a_line_is_found(start))
	{
		add_each_char_to_queue(buffer, start, nbytes);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (buffer == NULL)
			return (NULL);
	}
	add_each_char_to_queue(buffer, start, nbytes);
	display_queue(start);
	return (buffer);
}

int	main(void)
{
	int		fd;

	fd = open("gnlTester/files/nl", O_RDONLY);
	
	get_next_line(fd);

	get_next_line(fd);

	get_next_line(fd);
	
	get_next_line(fd);
	
	get_next_line(fd);

	get_next_line(fd);

	get_next_line(fd);
	
	get_next_line(fd);

	get_next_line(fd);

	get_next_line(fd);

	get_next_line(fd);

	get_next_line(fd);

	close(fd);
	
	return (0);
}