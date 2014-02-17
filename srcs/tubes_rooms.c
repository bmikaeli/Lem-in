/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 14:50:27 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/17 17:02:31 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void		ft_stocks_e(t_env *env, char *line)
{
	if (ft_strstr(line, "##start"))
	{
		env->z = 1;
		env->i--;
	}
	if (ft_strstr(line, "##end"))
	{
		env->z = 42;
		env->i--;
	}
}

void		ft_stock(t_env *env, char *line, char *tmp[], t_listt *list)
{
	env->tmp2  = ft_strsplit(line, ' ');
	if (env->tmp2[0][0] == '#' && env->tmp2[0][1] != '#')
		env->i--;
	else
		tmp[env->i] = ft_strdup(env->tmp2[0]);
	if (env->z == 1)
	{
		list = add_list(tmp[env->i], list, env);
		env->name_s = tmp[env->i];
		env->z = 0;
		env->i--;
	}
	if (env->z == 42)
	{
		env->name_e = tmp[env->i];
		env->z = 0;
		env->i--;
	}
	ft_stocks_e(env, line);
	if(ft_strstr(line, "-"))
		env->p++;
	env->i++;
}

void		ft_stock_tube(t_env *env, char *tmp[])
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

void		init_env(t_env *env)
{
	env->k = 0;
	env->p = 0;
	env->i = 0;
	env->z = 0;
	env->rempli_e = 1;
	env->count = 0;
	env->nb_fourmie = 0;
	env->tmp2 = NULL;
}

int			main(void)
{
	t_listt		list;
	t_env		env;
	char		*line;
	char		*tmp[255];

	init_env(&env);
	get_next_line(0, &line);
	env.nb_fourmie = ft_atoi(line);
	while (get_next_line(0, &line) == 1)
		ft_stock(&env, line, tmp, &list);
	ft_stock_tube(&env, tmp);
	list = *(add_list(ft_search_first(&env, env.name_s, env.k), &list, &env));
	env.tmpk = env.k;
	env.p = 0;
	while (env.tmpk >= 0)
	{
		env.z = ft_del_tube_start(&env, env.tmpk);
		if (env.z == 1)
			env.p++;
		env.tmpk--;
	}
	ft_rempli_list(&list, &env, list.name, (env.k - env.p));
	ft_parcour(&list, &env);
	return (0);
}
