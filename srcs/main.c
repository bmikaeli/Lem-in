/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:50:44 by aelola            #+#    #+#             */
/*   Updated: 2014/02/17 16:32:39 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>


void		ft_rempli_list(t_listt *list, t_env *env, char *salle, int k)
{
	salle = ft_search(env, salle, k);
	k--;
	if (ft_strcmp(salle, env->name_e) != 0 && k >= 0)
	{
		list = add_list(salle, list, env);
		ft_rempli_list(list, env, salle, k);
	}
	if (ft_strcmp(salle, env->name_e) == 0)
		list = add_list(env->name_e, list, env);
}

void		ft_parcourt(t_listt *list, t_env *env)
{
	t_listt		*start;
	int			tmp;

	start = list;
	list->rempli = PLEIN;

	while (env->rempli_e <= env->nb_fourmie)
	{
		tmp = env->count - 1;
		list = start;
		while (tmp > 0)
		{
			printf("L%d %s\n", env->rempli_e, list->name);
			list = list->next;
			tmp--;
		}
		env->rempli_e++;
	}
}
void	init_value(t_main *m, t_env *e)
{
	m->k = 0;
	m->p = 0;
	m->i = 0;
	m->z = 0;
	m->tmpk = 0;
	e->rempli_e = 1;
	e->count = 0;
}

int			main(void)
{
	t_listt		list;
	t_env		env;
	t_main		m;

	init_value(&m, &env);
	get_next_line(0, &m.line);
	env.nb_fourmie = ft_atoi(m.line);
	while (get_next_line(0, &m.line) == 1)
	{
		m.tmp2  = ft_strsplit(m.line, ' ');
		if (m.tmp2[0][0] == '#' && m.tmp2[0][1] != '#')
			m.i--;
		else
			m.tmp[m.i] = ft_strdup(m.tmp2[0]);
		if (m.z == 1)
		{
			list = *(add_list(m.tmp[m.i], &list, &env));
			env.name_s = m.tmp[m.i];
			m.z = 0;
			m.i--;
		}
		if (m.z == 42)
		{
			env.name_e = m.tmp[m.i];
			m.z = 0;
			m.i--;
		}
		if (ft_strstr(m.line, "##start"))
		{
			m.z = 1;
			m.i--;
		}
		if (ft_strstr(m.line, "##end"))
		{
			m.z = 42;
			m.i--;
		}
		if(ft_strstr(m.line, "-"))
			m.p++;
		m.i++;
	}
	m.z = 0;
	while (m.z < m.i)
	{
		if (m.z >= (m.i - m.p))
		{
			env.tube[m.k] = m.tmp[m.z];
			m.k++;
		}
		m.z++;
	}
	env.tube[m.k] = NULL;
	m.k--;
	list = *(add_list(ft_search_first(&env, env.name_s, m.k), &list, &env));
	m.tmpk = m.k;
	m.p = 0;
	while (m.tmpk >= 0)
	{
		m.z = ft_del_tube_start(&env, m.tmpk);
		if (m.z == 1)
			m.p++;
		m.tmpk--;
	}
	ft_rempli_list(&list, &env, list.name, (m.k - m.p));
	ft_parcourt(&list, &env);
	return (0);
}
