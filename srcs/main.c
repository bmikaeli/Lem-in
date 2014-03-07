/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:50:44 by aelola            #+#    #+#             */
/*   Updated: 2014/02/20 13:22:33 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

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
	env->tmp = (char **)malloc(sizeof(env->tmp) * 255);
}

int			main(void)
{
	t_listt		list;
	t_env		env;

	init_env(&env);
	get_next_line(0, &env.line);
	env.nb_fourmie = ft_atoi(env.line);
	while (get_next_line(0, &env.line) == 1)
		ft_stock(&env, env.line, env.tmp, &list);
	ft_stock_tube(&env, env.tmp);
	list = *(add_list(ft_search_first(&env, env.name_s), &list, &env));
	env.tmpk = env.k;
	env.p = 0;
	while (env.tmpk >= 0)
	{
		if (ft_del_tube_start(&env, env.tmpk) == 1)
			env.p++;
		env.tmpk--;
	}
	env.k -= env.p;
	ft_fill_list(&list, &env, list.name);
	ft_print_ant_way(&list, &env);
	return (0);
}
