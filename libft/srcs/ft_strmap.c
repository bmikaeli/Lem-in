/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:16:38 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:48 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	str = 0;
	i = 0;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		while (*(s + i))
		{
			*(str + i) = f(*(s + i));
			i++;
		}
	}
	return (str);
}
