/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <bvictoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:50:24 by bvictoir          #+#    #+#             */
/*   Updated: 2024/05/28 14:53:03 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h> 

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

#endif