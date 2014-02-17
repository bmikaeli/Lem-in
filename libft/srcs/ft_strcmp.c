/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:32:47 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:42 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		count;

	count = 0;
	while (*(s1 + count) != 0)
	{
		if (*(s1 + count) > *(s2 + count))
			return (*(s1 + count) - *(s2 + count));
		else if (*(s1 + count) < *(s2 + count))
			return (*(s1 + count) - *(s2 + count));
		count++;
	}
	if (ft_strlen(s1) > ft_strlen(s2))
		return (*(s1 + count));
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (0 - *(s2 + count));
	else
		return (0);
}
