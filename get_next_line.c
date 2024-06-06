/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <bvictoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:07:42 by bvkm              #+#    #+#             */
/*   Updated: 2024/06/06 11:22:31 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret > 0 && !ft_strchr(str, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("buf = %s | \n", buf);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf, ret);
	}
	free(buf);
	if (ret == 0)
	{
		line = ft_strjoin(str, "", 0);
		free(str);
		str = NULL;
		return (line);
	}
	line = ft_strjoin(str, "", 0);
	str = ft_strjoin(str, ft_strchr(str, '\n') + 1, ft_strlen(ft_strchr(str, '\n')));
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		line = get_next_line(fd);
		printf("line = %s\n", line);
		close(fd);
	}
	free(line);
	return (0);
}