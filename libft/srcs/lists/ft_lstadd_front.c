/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:58:34 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 14:28:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst && new_node)
	{
		if (!*lst)
			*lst = new_node;
		else
		{
			new_node->next = *lst;
			*lst = new_node;
		}
	}
}
