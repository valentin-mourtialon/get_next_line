/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:57:00 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/10 17:00:05 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_list
{
    char            character;
    struct s_list   *next;
} t_list;

typedef struct start_list
{
    t_list *ptr;
} start_list;

char        *get_next_line(int fd);
//void	    ft_putstr_fd(char *s, int fd);
//size_t	ft_strlen(const char *s);
//char	    *ft_strjoin(char const *s1, char const *s2);
//char	    **ft_split(char const *s, char c);
#endif