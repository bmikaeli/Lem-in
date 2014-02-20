/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:18:29 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/20 13:45:23 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define EMPTY	0
# define FULL	1
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
	char			*line;
	int				tmpk;
	char			**tmp;
}					t_env;

typedef struct		s_listt
{
	char			*name;
	int				rempli;
	struct s_listt	*end;
	struct s_listt	*next;
	struct s_listt	*prev;
}					t_listt;

void		print_path(int nb_ant, char *room);
char		*ft_search(t_env *env, char *room, int k);
t_listt		*add_list(char *name, t_listt *list, t_env *env);
int			ft_del_tube(t_env *env, int i);
int			ft_del_tube_start(t_env *env, int i);
char		*ft_search_first(t_env *env, char *room);
void		ft_stocks_necessary(t_env *env, char *line);
void		ft_stock(t_env *env, char *line, char *tmp[], t_listt *list);
void		ft_stock_tube(t_env *env, char *tmp[]);
void		init_env(t_env *env);
void		ft_fill_list(t_listt *list, t_env *env, char *room);
void		ft_print_ant_way(t_listt *list, t_env *env);

#endif /* !LEM-IN_H */

