/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 15:13:46 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/20 13:22:39 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

t_listt		*add_list(char *name, t_listt *list, t_env *env)
{
	t_listt	*t_new;

	t_new = malloc(sizeof(*t_new));
	t_new->name = name;
	t_new->rempli = EMPTY;
	list->next = t_new;
	t_new->prev = list;
	list = t_new;
	t_new->next = NULL;
	env->count++;
	return (list);
}

void		ft_fill_list(t_listt *list, t_env *env, char *room)
{
	room = ft_search(env, room, env->k);
	if (ft_strcmp(room, env->name_e) != 0 && env->k - 1 >= 0)
	{
		list = add_list(room, list, env);
		env->k--;
		ft_fill_list(list, env, room);
	}
	if (ft_strcmp(room, env->name_e) == 0)
		list = add_list(env->name_e, list, env);
	env->k++;
}

char		*ft_search_first(t_env *env, char *room)
{
	char	**tmp;
	int		tmp_k;

	tmp_k = env->k;
	while (env->k-- >= 0)
	{
		tmp = ft_strsplit(env->tube[env->k], '-');
		if (ft_strcmp(tmp[0], room) == 0)
		{
			env->k = tmp_k;
			return (tmp[1]);
		}
		else if (ft_strcmp(tmp[1], room) == 0)
		{
			env->k = tmp_k;
			return (tmp[0]);
		}
	}
	env->k = tmp_k;
	return (room);
}

char		*ft_search(t_env *env, char *room, int k)
{
	char	**tmp;
	int		i_tmp;

	i_tmp = k;
	while (i_tmp >= 0)
	{
		tmp = ft_strsplit(env->tube[i_tmp], '-');
		if (ft_strcmp(tmp[0], room) == 0 || ft_strcmp(tmp[1], room) == 0)
		{
			if (ft_strcmp(tmp[0], env->name_e) == 0 ||
				ft_strcmp(tmp[1], env->name_e) == 0)
				return (env->name_e);
		}
		i_tmp--;
	}
	while (k >= 0)
	{
		tmp = ft_strsplit(env->tube[k], '-');
		if (ft_strcmp(tmp[0], room) == 0 && ft_del_tube(env, k))
			return (tmp[1]);
		else if (ft_strcmp(tmp[1], room) == 0 && ft_del_tube(env, k))
			return (tmp[0]);
		k--;
	}
	return (room);
}
