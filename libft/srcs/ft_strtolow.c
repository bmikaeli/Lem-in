/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:44:00 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:57 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolow(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			str[i] = s[i] + 32;
		else
			str[i] = s[i];
		i++;
	}
	return (str);
}
