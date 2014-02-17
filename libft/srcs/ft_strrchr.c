/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:28:56 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:54 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, char c)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (*(s + i--) == c)
			return ((char *)s + i + 1);
	}
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	else
		return (0);
}
