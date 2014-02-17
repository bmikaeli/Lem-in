/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:07:25 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:44 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*dest;
	int		count;

	count = 0;
	dest = (char*)ft_memalloc(sizeof(char) * (ft_strlen(src) + 1));
	if (src && dest != NULL)
	{
		while (*(src + count) != 0)
		{
			*(dest + count) = *(src + count);
			count++;
		}
	}
	if (src == 0)
		*dest = 0;
	return (dest);
}
