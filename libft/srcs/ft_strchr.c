/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:28:56 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:41 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	int		i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i++) == c)
			return ((char *)s + i - 1);
	}
	if (c == '\0')
		return ((char *)s + i);
	else
		return (0);
}
