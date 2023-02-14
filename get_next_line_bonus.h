/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:30:58 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/14 17:31:17 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

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

int		ft_strchr(char *s, char c);

char	*ft_strjoin(char *s1, char *s2, int ilen);

char	*ft_cl(char **buffer);

char	*ft_strndup(char *s, int len);

#endif
