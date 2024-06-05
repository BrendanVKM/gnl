/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <bvictoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:03:55 by bvictoir          #+#    #+#             */
/*   Updated: 2024/06/05 20:38:08 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			str[i++] = s1[j++];
	j = 0;
	while (i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
