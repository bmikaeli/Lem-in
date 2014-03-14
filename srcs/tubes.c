/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:44:37 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/12 15:15:35 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

int		ft_del_tube(t_env *env, int i)
{
	while (env->tube[i] != NULL)
	{
		env->tube[i] = env->tube[i + 1];
		i++;
	}
	return (1);
}

int		ft_del_tube_start(t_env *env, int i)
{
	char	**tmp;

	tmp = ft_strsplit (env->tube[i], '-');
	if (!tmp[0] || !tmp[1])
	{
		ft_putstr("⚠️ map_error (split error), Maybe map error ?⚠️\n");
		exit(1);
	}
	if (!ft_strcmp(tmp[0], env->name_s) || !ft_strcmp(tmp[1], env->name_s))
	{
		ft_del_tube(env, i);
		return (1);
	}
	return (0);
}

void	ft_stock_tube(t_env *env, char *tmp[])
{
	env->z = 0;
	while (env->z < env->i)
	{
		if (env->z >= (env->i - env->p))
		{
			env->tube[env->k] = tmp[env->z];
			env->k++;
		}
		env->z++;
	}
	env->tube[env->k] = NULL;
	env->k--;
}


void	print_path(int nb_ant, char *room, t_env *e)
{
	check_boucle(nb_ant, room, e);
	ft_putstr("L");
	ft_putnbr(nb_ant);
	ft_putchar(' ');
	if (ft_strcmp(room, "kikoololilol"))
		ft_putstr(room);
	ft_putstr(" ");
}
