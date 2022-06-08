/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:50:38 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/08 12:00:10 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	find_new_line(char	*s, int i)
{
	if (s[i] == '\0')
		return (0);
	if (s[i] == '\n')
		return (i);
	return (find_new_line(s, i + 1));
}*/

char	*get_next_line(int fd)
{
	//static int	cursor = 0;

	static char	buffer[BUFFER_SIZE + 1]; // +1 for the \n
	int			nbytes;

	nbytes = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\n';
	
	if (nbytes > 0)
		ft_putstr_fd(buffer, 1);
	else
		write(1, "\n", 1);


	//nbytes = read(fd, buffer, sizeof(char));

	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("testfiles/test6.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);

	return (0);
}