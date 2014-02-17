/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeduplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 08:22:28 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:40 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_removeduplicates(char **s, char c)
{
	int		i;
	int		j;
	char	*str;
	char	*p_s;

	i = 0;
	j = 0;
	p_s = *s;
	str = ft_strnew(ft_strlen(p_s) + 1);
	while (p_s[i])
	{
		if (p_s[i] == c)
		{
			if (p_s[i + 1] != c)
				str[j++] = p_s[i];
		}
		else
			str[j++] = p_s[i];
		i++;
	}
	free(p_s);
	*s = str;
}
