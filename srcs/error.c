/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:47:26 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/12 14:56:47 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void	check_boucle(char *name)
{
	static char		*last_name;

	if (last_name == name)
	{
		ft_putstr("\n ⚠️  Something went wrong, there is probably some");
		ft_putstr(" problems with your map ⚠️ \n");
		exit(1);
	}
	last_name = name;
}
