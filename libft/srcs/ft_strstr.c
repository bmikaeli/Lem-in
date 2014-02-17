/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:40:46 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compare_sub_str(const char *str1, const char *str2)
{
	int		count;
	int		find;

	find = 1;
	count = 0;
	while (*(str2 + count) != 0)
	{
		if (*(str2 + count) != *(str1 + count))
			find = 0;
		count++;
	}
	return (find);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	if (ft_strlen(s2) >= 1)
	{
		while (*(s1 + i) != 0 && find == 0)
		{
			if (*(s1 + i) == *s2)
				find = ft_compare_sub_str(s1 + i, s2);
			i++;
		}
		if (find == 1 && ft_strlen(s2) <= ft_strlen(s1))
			return ((char *) s1 + i - 1);
		else
			return (0);
	}
	else
		return ((char *) s1);
}
