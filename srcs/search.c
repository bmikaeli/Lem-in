/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 15:13:46 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/17 17:02:28 by bmikaeli         ###   ########.fr       */
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
	{
		list = add_list(env->name_e, list, env);
	}
}

// void		ft_parcour(t_listt *list, t_env *env)
// {
// 	int			tmp_fourmi;

// 	tmp_fourmi = 0;
// 	list->rempli = PLEIN;
// 	while (env->rempli_e <= env->nb_fourmie)
// 	{
// 		tmp_fourmi = 0;
// //		printf("rempli_e : %d\n", env->rempli_e);
// 		while (list->next->rempli == PLEIN)
// 		{
// 			printf("name_next : %s\n", list->name);
// 			list = list->next;
// 		}
// 		list->rempli = PLEIN;
// 		printf("last_rempli : %s\n", list->name);
// 		while (ft_strcmp(list->name, list->name) == 0)
// 		{
// 			printf("rempli : %d | rempli->next : %d | list->name : %s\n", list->rempli, list->next->rempli, list->name);
// 			if (list->rempli == PLEIN && list->next->rempli == VIDE &&
// 				ft_strcmp(list->next->name, env->name_e) != 0)
// 			{
// 				list->next->rempli = PLEIN;
// 				list->rempli = VIDE;
// 				printf("L%d %s\n", tmp_fourmi, list->name);
// 				tmp_fourmi++;
// 			}
// 			printf("list->name : %s\n", list->name);
// 			if (list->rempli == PLEIN &&
// 				ft_strcmp(list->next->name, env->name_e) == 0)
// 			{
// 				printf("L%d %s\n", tmp_fourmi, env->name_e);
// 				list->rempli = VIDE;
// 				env->rempli_e++;
// 				tmp_fourmi++;
// 			}
// 			list = list->next;
// 		}
// 		printf("list->name : %s\n", list->name);
// 		env->rempli_e++;
// 	}
// }

void		ft_parcour(t_listt *list, t_env *env)
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
