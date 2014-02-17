/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 15:13:46 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/17 16:33:36 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

char	*ft_search_first(t_env *env, char *salle, int k)
{
	char	**tmp;

	while (k >= 0)
	{
		tmp = ft_strsplit(env->tube[k], '-');
		if (ft_strcmp(tmp[0], salle) == 0)
			return (tmp[1]);
		else if (ft_strcmp(tmp[1], salle) == 0)
			return (tmp[0]);
		k--;
	}
	return (salle);
}

char	*ft_search(t_env *env, char *salle, int k)
{
	char	**tmp;
	int		i_tmp;

	i_tmp = k;
	while (i_tmp >= 0)
	{
		tmp = ft_strsplit(env->tube[i_tmp], '-');
		if (ft_strcmp(tmp[0], salle) == 0 || ft_strcmp(tmp[1], salle) == 0)
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
		if (ft_strcmp(tmp[0], salle) == 0)
		{
			ft_del_tube(env, k);
			return (tmp[1]);
		}
		else if (ft_strcmp(tmp[1], salle) == 0)
		{
			ft_del_tube(env, k);
			return (tmp[0]);
		}
		k--;
	}
	return (salle);
}
