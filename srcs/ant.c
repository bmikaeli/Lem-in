/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:47:26 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/12 15:09:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void		ft_rempli_list(t_listt *list, t_env *env, char *room, int k)
{
	env->k = k;
	room = ft_search(env, room, k);
	k--;
	if (ft_strcmp(room, env->name_e) != 0 && k >= 0)
	{
		list = add_list(room, list, env);
		ft_rempli_list(list, env, room, k);
	}
	if (ft_strcmp(room, env->name_e) == 0)
		list = add_list(env->name_e, list, env);
}

int			ft_print_last(t_env *env, t_listt *list, int tmp)
{
	if (env->z == 1)
	{
		print_path(tmp - 1, env->name_e);
		env->z = 0;
	}
	if (list->next && !ft_strcmp(list->next->name, env->name_e))
	{
		if (tmp < env->nb_fourmie && list->rempli == FULL)
			env->z = 1;
		env->rempli_e++;
	}
	return (env->z);
}

void		ft_print_start(int tmp, t_listt *list, t_env *env, t_listt *start)
{
	if (!list->next)
	{
		ft_putendl("⚠️  theres a problem, somewhere... can't help u more ⚠️ \n");
		exit(1);
	}
	if (list->next && list && !ft_strcmp(list->name, start->name))
	{
		if (tmp < env->nb_fourmie)
			print_path(tmp, list->name);
		list->next->rempli = FULL;
		list->rempli = EMPTY;
		tmp++;
	}
	ft_putchar('\n');
}

int			ft_print(t_listt *list, t_listt *start, t_env *env, int tmp)
{
	tmp = env->rempli_e;
	list = start;

	while (list->next && list->next->rempli == FULL)
		list = list->next;
	env->z = ft_print_last(env, list, tmp);
	while (list && ft_strcmp(list->name, start->name))
	{
		if (tmp < env->nb_fourmie)
			print_path(tmp, list->name);
		if (list->next && !ft_strcmp(list->next->name, env->name_e))
			list->rempli = EMPTY;
		else
		{
			if (list->next)
				list->next->rempli = FULL;
			list->rempli = EMPTY;
		}
		list = list->prev;
		tmp++;
	}
	ft_print_start(tmp, list, env, start);
	return (env->rempli_e);
}

void		ft_print_ant_way(t_listt *list, t_env *env)
{
	t_listt		*start;
	int			tmp;

	env->z = 0;
	env->rempli_e = 0;
	tmp = 0;
	tmp = env->nb_fourmie;
	start = list;
	list->rempli = FULL;
	while (env->rempli_e <= env->nb_fourmie)
		ft_print(list, start, env, tmp);
}
