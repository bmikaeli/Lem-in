/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:18:29 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/17 17:04:05 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define VIDE	0
# define PLEIN	1

# include <libft.h>
# include <stdio.h>
# include <get_next_line.h>

typedef struct		s_env
{
	char			*name_e;
	char			*name_s;
	char			*tube[255];
	char			**tmp2;
	int				nb_fourmie;
	int				rempli_e;
	int				count;
	int				i;
	int				z;
	int				p;
	int				k;
	int				tmpk;
}					t_env;

typedef struct		s_listt
{
	char			*name;
	int				rempli;
	struct s_listt	*end;
	struct s_listt	*next;
	struct s_listt	*prev;
}					t_listt;

char		*ft_search(t_env *env, char *salle, int k);
int			ft_del_tube_start(t_env *env, int i);
t_listt		*add_list(char *name, t_listt *list, t_env *env);
void		ft_del_tube(t_env *env, int i);
int			ft_del_tube_start(t_env *env, int i);
char		*ft_search_first(t_env *env, char *salle, int k);
char		*ft_search(t_env *env, char *salle, int k);
void		ft_stocks_e(t_env *env, char *line);
void		ft_stock(t_env *env, char *line, char *tmp[], t_listt *list);
void		ft_stock_tube(t_env *env, char *tmp[]);
void		init_env(t_env *env);
void		ft_rempli_list(t_listt *list, t_env *env, char *salle, int k);
void		ft_parcour(t_listt *list, t_env *env);

#endif /* !LEM-IN_H */

