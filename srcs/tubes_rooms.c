/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 14:50:27 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/17 16:10:45 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

t_listt		*add_list(char *name, t_listt *list, t_env *env)
{
	t_listt		*t_new;

	t_new = malloc(sizeof *t_new);
	if (t_new != NULL)
	{
		t_new->name = name;
		t_new->next = NULL;
		t_new->rempli = 0;
		if (env->count == 0)
		{
			t_new->next = NULL;
			list = t_new;
			list->prev = NULL;
		}
		else
		{
			list->next = t_new;
			t_new->prev = list;
			t_new->next = NULL;
			list = t_new;
		}
		env->count++;
	}
	return (list);
}

void		ft_del_tube(t_env *env, int i)
{
	while (env->tube[i] != NULL)
	{
		env->tube[i] = env->tube[i + 1];
		i++;
	}
}

int			ft_del_tube_start(t_env *env, int i)
{
	char	**tmp;

	tmp = ft_strsplit (env->tube[i], '-');
	if (ft_strcmp(tmp[0], env->name_s) == 0 || ft_strcmp(tmp[1], env->name_s) == 0)
	{
		ft_del_tube(env, i);
		return (1);
	}
	return (0);
}
