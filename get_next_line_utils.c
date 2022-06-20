/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:20:47 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/20 09:40:18 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	size_t	total_length;
	size_t	i;
	char	*output;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	total_length = s1_length + s2_length;
	output = malloc((total_length + 1) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (i < s1_length)
	{
		output[i] = s1[i];
		i++;
	}
	while (i - s1_length < s2_length)
	{
		output[i] = s2[i - s1_length];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char)c == 0)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*output;
	size_t	i;

	if (size != 0 && nmemb > INT_MAX / size)
		return (NULL);
	output = malloc(nmemb * size);
	if (!output)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((unsigned char *)output)[i++] = '\0';
	return (output);
}

int	read_file(int fd, char **buffer, int *nbytes, int buffersize)
{
	*nbytes = read(fd, *buffer, buffersize);
	if (*nbytes == -1)
	{
		free(*buffer);
		return (0);
	}
	(*buffer)[*nbytes] = '\0';
	return (1);
}
