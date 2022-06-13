/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:57:00 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/11 13:28:47 by vmourtia         ###   ########.fr       */
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

typedef struct list_start
{
    t_list *first;
} list_start;

void	    ft_putchar_fd(char c, int fd);
t_list	    *lst_new(char c);
list_start	*init_queue(void);
t_list	    *lst_last_element(list_start *start);
void	    lst_delete_one(list_start *start);
void	    add_each_char_to_queue(char *src, list_start *start, int nbytes);
int	        a_line_is_found(list_start *start);
void	    display_queue(list_start *start);
char        *get_next_line(int fd);
#endif