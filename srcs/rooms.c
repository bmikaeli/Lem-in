/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 14:50:27 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/12 15:15:46 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void		ft_stocks_necessary(t_env *env, char *line)
{
	if (!ft_strcmp(line, "##end") && ft_strcmp(env->name_e, "kikoololilol"))
	{
		printf("⚠️ map end error ⚠️ \n");
		exit(0);
	}
	if (!ft_strcmp(line, "##start") && ft_strcmp(env->name_s, "kikoololilol"))
	{
		printf("⚠️ map start error ⚠️\n");
		exit(0);
	}
	if (!ft_strcmp(line, "##start"))
	{
		env->z = 1;
		env->i--;
	}
	if (!ft_strcmp(line, "##end"))
	{
		env->z = 42;
		env->i--;
	}
}

void		ft_stock(t_env *env, char *line, char *tmp[], t_listt *list)
{
	ft_putendl(line);
	if (!line[0] || (line[0] == '#' && line[1] != '#'))
		return ;
	env->tmp2  = ft_strsplit(line, ' ');
	if (!ft_strncmp(line, "##", 2))
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
	ft_stocks_necessary(env, line);
	if (ft_strstr(line, "-"))
		env->p++;
	env->i++;
}
