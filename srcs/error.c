/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:47:26 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/22 11:41:25 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void	check_boucle(int nb_ant, char *name, t_env *e)
{
	static char		last_ant[2][600];
	static int		i;

	if (nb_ant == last_ant[0][0] && !ft_strcmp(name, last_ant[1]))
	{
		ft_putstr("\n ⚠️  Something went wrong, there is probably some");
		ft_putstr(" problems with your map ⚠️ \n");
		exit(1);
	}
	i++;
	if (i % e->nb_fourmie == 1)
	{
		last_ant[0][0] = nb_ant;
		ft_strcpy(last_ant[1], name);
	}
}
