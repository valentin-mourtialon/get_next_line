/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-next-line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:50:38 by vmourtia          #+#    #+#             */
/*   Updated: 2022/05/13 16:34:43 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get-next-line.h"

int	find_new_line(char	*s, int i)
{
	if (s[i] == '\0')
		return (0);
	if (s[i] == '\n')
		return (i);
	return (find_new_line(s, i + 1));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			nbytes;
	int			i;
	int			j;

	nbytes = read(fd, buffer, BUFFER_SIZE);
	if (nbytes == -1)
		return (NULL);
		
	new_line = find_new_line(buffer, 0);
	while (!new_line)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		temp = buffer;
		nbytes = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(temp, buffer);
		new_line = find_new_line(buffer, new_line);
	}
	//line = malloc((++new_line + 1) * sizeof(char));

	
	/*j = 0;
	while (j < new_line)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';*/
	
	return (line);
}*/

int	main(void)
{
	/*int		fd;
	
	fd = open("test.txt", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	close(fd);*/
	char	str[]="maTaPaZa\n";

	printf("%d", find_new_line(str, 0));
	return (0);
}