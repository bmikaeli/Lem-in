/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:09:32 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:30 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cursor;
	t_list	*cursor_new;

	new = 0;
	cursor = lst;
	while (cursor)
	{
		cursor_new = ft_lstnew(cursor->content, cursor->content_size);
		f(cursor_new);
		if (!new)
			new = cursor_new;
		cursor_new = cursor_new->next;
		cursor = cursor->next;
	}
	return (new);
}
