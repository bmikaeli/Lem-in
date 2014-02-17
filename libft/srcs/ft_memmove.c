/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:37:24 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:34 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*ps1;
	char	*ps2;

	ps1 = (char *) s1;
	ps2 = (char *) s2;
	if (ps2 <= ps1)
	{
		ps1 += n - 1;
		ps2 += n - 1;
		while (n--)
			*ps1-- = *ps2--;
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
