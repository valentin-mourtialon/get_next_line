/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:40:56 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/22 11:10:06 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;
	int			nbytes;
	char		*buffer;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr(memory, '\n') && nbytes != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 0)
			return (free(buffer), NULL);
		buffer[nbytes] = 0;
		memory = ft_strjoin(memory, buffer);
		if (!memory)
			return (NULL);
	}
	line = write_line_from_memory(memory);
	memory = clear_memory(memory);
	return (line);
}

int	main(void)
{
	int fd = open("testfiles/test0.txt", O_RDONLY);
	char *line;

	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd);
		if (line == NULL)
			printf("%p\n", line);	
		else
			printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
