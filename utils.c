/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:55:07 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/09 11:56:04 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

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

/* -------------------- SPLIT -------------------- */

static int	is_sep(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb_of_words;

	if (!(*s))
		return (0);
	nb_of_words = 0;
	if (!is_sep(s[0], c))
		nb_of_words++;
	i = 1;
	while (s[i])
	{
		if (is_sep(s[i - 1], c) && !is_sep(s[i], c))
			nb_of_words++;
		i++;
	}
	return (nb_of_words);
}

static void	alloc_space_for_words(char **split, char const *str, char c)
{
	int	i;
	int	word_position;

	word_position = 0;
	while (*str)
	{		
		while (is_sep(*str, c) && *str)
			str++;
		i = 0;
		while (!is_sep(str[i], c) && str[i])
			i++;
		if (i != 0)
			split[word_position] = malloc((i + 1) * sizeof(char));
		word_position++;
		str = (str + i);
	}
}

static void	put_words(char **split, char const *str, char c, int nb_of_words)
{
	int	x;
	int	y;
	int	i;

	if (*str)
	{
		x = 0;
		i = 0;
		while (x < nb_of_words)
		{
			while (str[i] && is_sep(str[i], c))
				i++;
			y = 0;
			while (str[i] && !is_sep(str[i], c))
				split[x][y++] = str[i++];
			split[x][y] = '\0';
			x++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nb_of_words;

	if (!s)
		return (NULL);
	nb_of_words = count_words(s, c);
	split = malloc((nb_of_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	alloc_space_for_words(split, s, c);
	put_words(split, s, c, nb_of_words);
	split[nb_of_words] = NULL;
	return (split);
}

