/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:47:26 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/19 16:19:36 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void		ft_rempli_list(t_listt *list, t_env *env, char *salle, int k)
{
	env->k = k;
	salle = ft_search(env, salle);
	k--;
	if (ft_strcmp(salle, env->name_e) != 0 && k >= 0)
	{
		list = add_list(salle, list, env);
		ft_rempli_list(list, env, salle, k);
	}
	if (ft_strcmp(salle, env->name_e) == 0)
		list = add_list(env->name_e, list, env);
}

int			ft_print_last(t_env *env, t_listt *list, int tmp)
{
	if (env->z == 1)
	{
		printf("L%d %s ", tmp - 1, env->name_e);
		env->z = 0;
	}
	if (ft_strcmp(list->next->name, env->name_e) == 0)
	{
		if (tmp < env->nb_fourmie && list->rempli == FULL)
			env->z = 1;
		env->rempli_e++;
	}
	return (env->z);
}

void		ft_print_start(int tmp, t_listt *list, t_env *env, t_listt *start)
{
	if (ft_strcmp(list->name, start->name) == 0)
	{
		if (tmp < env->nb_fourmie)
			printf("L%d %s ", tmp, list->name);
		list->next->rempli = FULL;
		list->rempli = EMPTY;
		tmp++;
	}
	printf("\n");
}

int			ft_print(t_listt *list, t_listt *start, t_env *env, int tmp)
{
	tmp = env->rempli_e;
	list = start;
	while (list->next->rempli == FULL)
		list = list->next;
	env->z = ft_print_last(env, list, tmp);
	while (ft_strcmp(list->name, start->name) != 0)
	{
		if (tmp < env->nb_fourmie)
			printf("L%d %s ", tmp ,list->name);
		if (ft_strcmp(list->next->name, env->name_e) == 0)
			list->rempli = EMPTY;
		else
		{
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
