/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:50:38 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/08 16:33:30 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	fill_buffer(char **buffer, int fd)
{
	int nbytes;
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		nbytes = read(fd, (*buffer + i), sizeof(char));
		if (nbytes < 0)
			return (-1);
		if ((*buffer)[i] == '\n')
			break;
		i++;
	}
	if (i == BUFFER_SIZE)
	{
		(*buffer)[i] = '\0'; // When buffer length < line length
		return (1);
	}
	else
	{
		(*buffer)[i + 1] = '\0';
		return (0);
	}
	return (i);
}*/

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			i;
	int			nbytes;

	i = 0;
	
	while (i > 0 && i < BUFFER_SIZE)
	{
		printf("%c", *buffer);
		if (buffer[i] == '\n')
			i = 0;
		else
			i++;
	}

	nbytes = read(fd, buffer, BUFFER_SIZE);
	if (nbytes < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';

	while(i < BUFFER_SIZE)
	{
		printf("%c", buffer[i]);
		if (buffer[i] == '\n')
			i = 0;
		else
			i++;
	}
	
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("testfiles/test5.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}