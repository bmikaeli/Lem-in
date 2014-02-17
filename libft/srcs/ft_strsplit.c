/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:07:10 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_part_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len = len + 1;
	return (len);
}

static int		ft_part_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (*(s + i))
	{
		if (*(s + i) == c && *(s + i + 1) && *(s + i + 1) != c)
			count = count + 1;
		i = i + 1;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		part_count;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	part_count = ft_part_count(s, c);
	array = (char **)malloc(sizeof(char *) * (part_count + 1));
	array[part_count] = 0;
	while (j < part_count && *(s + i))
	{
		len = ft_part_len(s + i, c);
		if (len > 0)
		{
			array[j] = ft_strsub(s, i, len);
			j = j + 1;
		}
		i = i + len + 1;
	}
	return (array);
}
