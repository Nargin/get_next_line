/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:24:18 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/08 20:07:17 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>


char	*get_next_line(int fd);

char	*reader(char *buffer, int fd);

int		ft_strlen(char *s);

char	*ft_strchr(char *s, char c);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_cl(char *str);

char	*ft_nl(char *str);

void	*ft_calloc(int n, int s);

#endif
