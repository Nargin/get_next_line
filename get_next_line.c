/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/05 16:10:56 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	int		len;
	char	*nx;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len = strlenn(s1, 1) + strlenn(s2, 1);
	nx = malloc((len + 1) * sizeof(char));
	if (!nx)
		return (0);
	i = 0;
	k = 0;
	while (s1[k] && i < len)
		nx[i++] = s1[k++];
	k = 0;
	while (s2[k] && i < len)
		nx[i++] = s2[k++];
	nx[i] = 0;
	return (nx);
}

int	ft_strchr(char *s,  char n)
{
	while (*s)
		if (*s++ == n)
			return (1);
	return (0);
}

int	strlenn(char *s, int option)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	if (option == 1)
		while (*s++)
			i++;
	else
		while (s[i] || s[i] != '\n')
			i++;
	return (i);
}

char	*reader(char *buffer, int fd)
{
	char	*temp;
	int	rfl;

	rfl = 1;
	temp = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n') && rfl)
	{
		rfl = read(fd, temp, BUFFER_SIZE);
		printf("%s\n", temp);
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*tmp;

	if (!fd || !read(fd, 0, 0) || !BUFFER_SIZE)
		return (0);
	buffer = reader(buffer, fd);
	printf("%s\n", buffer);
	return (buffer);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);

	printf("fd : %d\n", fd);
	get_next_line(fd);
	return (0);
}
