/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:40:45 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/05 11:53:58 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*get_next_line(int fd)
{
	char	*store;
	char	*line;

	store = malloc(7);
	if (!store || fd < 0)
		return (free(store), NULL);
	line = store;
	while (read(fd, store, 1) > 0 && *store != '\n')
		store++;
	if (store == line && *store != '\n')
		return (free(store), NULL);
	*++store = '\0';
	return (line);
}
