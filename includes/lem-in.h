/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:18:29 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/02/17 16:13:33 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define LEM_IN_H

# include <libft.h>
# include <stdio.h>
# include <libft.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define VIDE 0
# define PLEIN 1

typedef struct	s_env
{
	char	*name_e;
	char	*name_s;
	char	*tube[3000];
	int		nb_fourmie;
	int		rempli_e;
	int		count;
}				t_env;

typedef struct		s_listt
{
	char			*name;
	int				rempli;
	struct s_listt	*end;
	struct s_listt	*next;
	struct s_listt	*prev;
}					t_listt;

typedef struct		s_main
{
	char		*line;
	char		*tmp[3000];
	int			z;
	int			i;
	int			p;
	int			k;
	int			tmpk;
	char		**tmp2;
}					t_main;

t_listt		*add_list(char *name, t_listt *list, t_env *env);
void		ft_del_tube(t_env *env, int i);
int			ft_del_tube_start(t_env *env, int i);
char	*ft_search_first(t_env *env, char *salle, int k);
char	*ft_search(t_env *env, char *salle, int k);
void		ft_rempli_list(t_listt *list, t_env *env, char *salle, int k);
void		ft_parcourt(t_listt *list, t_env *env);


#endif /* !LEM-IN_H */

