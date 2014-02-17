/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:34:07 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:54 by bmikaeli         ###   ########.fr       */
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

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	if (ft_strlen(s2) >= 1)
	{
		while (*(s1 + i) && !find && i < (int)n)
		{
			if (*(s1 + i) == *s2 && n - i >= ft_strlen(s2))
				find = ft_compare_sub_str(s1 + i, s2);
			i++;
		}
		if (find && ft_strlen(s2) <= ft_strlen(s1) && n >= ft_strlen(s2))
			return ((char *) s1 + i - 1);
		else
			return (0);
	}
	else
		return ((char *) s1);
}
