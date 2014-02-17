/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 08:59:39 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:46 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size_s1;
	int		size_s2;

	str = 0;
	if (s2)
	{
			if (s1)
			{
					size_s1 = ft_strlen(s1);
					size_s2 = ft_strlen(s2);
					str = ft_strnew(size_s1 + size_s2 + 1);
					if (str)
					{
							ft_strlcat(str, s1, size_s1 + 1);
							ft_strlcat(str, s2, size_s1 + size_s2 + 1);
					}
			}
		else
			str = ft_strdup(s2);
	}
	return (str);
}
