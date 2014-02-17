/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:32:34 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:47 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;
	size_t	dest_len;

	i = size;
	ptr_dst = dst;
	ptr_src = (char *)src;
	while (i-- && *ptr_dst)
		ptr_dst++;
	dest_len = ptr_dst - dst;
	i = size - dest_len;
	if (!i)
		return (dest_len + ft_strlen(ptr_src));
	while (*ptr_src)
	{
		if (i != 1)
		{
			*ptr_dst++ = *ptr_src;
			i--;
		}
		ptr_src++;
	}
	*ptr_dst = '\0';
	return (dest_len + (size_t)(ptr_src - src));
}
