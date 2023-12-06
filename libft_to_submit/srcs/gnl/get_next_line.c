/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:40:45 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/06 19:51:50 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*get_next_line(int fd)
{
	char	*store;
	char	*line;
	int		length;

	length = 7;
	store = malloc(length);
	if (!store || fd < 0)
		return (free(store), NULL);
	while (length--)
		*(store + length) = 0;
	line = store;
	while (read(fd, store, 1) > 0 && *store != '\n')
		store++;
	if (store == line && *store != '\n')
		return (free(store), NULL);
	*++store = '\0';
	return (line);
}
