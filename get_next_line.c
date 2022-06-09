/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:50:38 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/09 12:19:23 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

int	consume_buffer(char *buffer, int i, int n_calls)
{
	if (n_calls != 0)
	{
		if (buffer[i] == '\n')
		{
			write(1, "\n", 1);
			return (i);
		}
		else if (buffer[i] == '\0')
			return (-1);
		else
		{
			write(1, &buffer[i], 1);
			return consume_buffer(buffer, i + 1, n_calls);
		}
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	n_calls = 0;
	int			i;
	int			nbytes;
	
	i = consume_buffer(buffer, 0, n_calls);
	n_calls++;
	while (i < 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 0)
			return (NULL);
		i = consume_buffer(buffer, 0, n_calls);
	}
	printf("\ti = %d\n", i);
	ft_memmove(&buffer[0], &buffer[i + 1], BUFFER_SIZE - i);
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("testfiles/test5.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}

// A la fin retourne cdA car il a atteint la fin du 
// fichier et que je n ai pas gere ce cas cd nbytes < BUFFER_SIZE