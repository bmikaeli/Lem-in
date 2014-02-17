/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:08:07 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:57 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_ok(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

void	ft_trim_end(char *str, size_t size)
{

	str += size - 1;
	while (ft_is_ok(*str) && size--)
	{
		*str = 0;
		str--;
	}
}

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*final;

	final = 0;
	if (s)
	{
		str = ft_strnew(ft_strlen(s) + 1);
		ft_strcat(str, s);
		while (ft_is_ok(*str) && *str)
			str++;
		ft_trim_end(str, ft_strlen(str));
		final = ft_strnew(ft_strlen(str) + 1);
		ft_strcat(final, str);
	}
	return (final);
}
