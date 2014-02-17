/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:35:49 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:31 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *) ft_memalloc(sizeof(t_list));
	if (!content)
		content_size = 0;
	if (elem)
	{
		elem->content = ft_memalloc((content_size + 1) * sizeof(content));
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->next = NULL;
	}
	return (elem);
}
