/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:40:56 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/15 16:35:09 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*retrieve_new_line(char *memory)
{
	char	*line;
	int		line_length;
	int		i;

	if (*memory == 0)
		return (NULL);
	line_length = 0;
	while (memory[line_length] && memory[line_length] != '\n')
		line_length++;
	line = ft_calloc(line_length + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < line_length)
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] && memory[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*join_and_free(char *memory, char *buffer)
{
	char	*memory_temp;

	memory_temp = ft_strjoin(memory, buffer);
	free(memory);
	return (memory_temp);
}

/* Writes memory until \n or EOF*/
char	*write_memory(int fd, char *memory)
{
	int		nbytes;
	char	*buffer;
	
	if (!memory)
	{
		memory = ft_calloc(1, sizeof(char));
		if (!memory)
			return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		memory = join_and_free(memory, buffer);
		if (ft_strchr(memory, '\n') != NULL)
			break;
	}
	free(buffer);
	return (memory);
}

char	*clear_memory(char *memory, int line_length)
{
	char	*clear_memory;
	int		i;

	if (!memory)
		return (NULL);
	i = 0;
	while (memory[i])
		i++;
	clear_memory = ft_calloc(i - line_length + 1, sizeof(char));
	if (clear_memory == NULL)
		return (NULL);
	i = 0;
	while (memory[line_length])
		clear_memory[i++] = memory[line_length++];
	free(memory);
	return (clear_memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;
	int			line_length;
	
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	memory = write_memory(fd, memory);
	if (memory == NULL)
		return (NULL);
	line = retrieve_new_line(memory);
	if (line == NULL)
		return (NULL);
	line_length = ft_strlen(line);
	memory = clear_memory(memory, line_length);
	if (memory == NULL)
		return (NULL);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		i = 0;
	char	*line;

	fd = open("gnlTester/files/41_no_nl", O_RDONLY);
	//fd = open("testfiles/test2.txt", O_RDONLY);

	while(i < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break;	
		i++;
	}

	close(fd);
	
	return (0);
}*/