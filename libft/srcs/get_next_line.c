/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:26:20 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:59 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <get_next_line.h>

int		ft_as_nextline(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return ((int)i);
		i = i + 1;
	}
	return (-1);
}

int		ft_process_buff(int const fd, char *shift, char **str)
{
	char	*buff;
	int		y;
	int		ret;

	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (0);
	y = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = 0;
		if ((y = ft_as_nextline(buff)) >= 0)
		{
			ft_strcpy(shift, buff + y + 1);
			buff[y] = 0;
			*str = ft_strjoin(*str, buff);
			break ;
		}
		*str = ft_strjoin(*str, buff);
	}
	free(buff);
	return (1);
}

int		ft_process_shift(char *shift, char **str, char **line)
{
	char	*tmp;
	int		y;

	y = 0;
	if (ft_strcmp(shift, ""))
	{
		if ((y = ft_as_nextline(shift)) >= 0)
		{
			*str = ft_strnew(y + 1);
			ft_strncpy(*str, shift, y);
			if (!(tmp = ft_strnew(ft_strlen(shift + y + 1) + 1)))
				return (-1);
			ft_strcpy(tmp, shift + y + 1);
			shift[0] = 0;
			ft_strcpy(shift, tmp);
			free(tmp);
			*line = *str;
			return (1);
		}
		*str = ft_strjoin(*str, shift);
		shift[0] = 0;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		*str;
	static char	shift[BUFF_SIZE + 1] = {0};
	int			result;

	str = 0;
	result = 0;
	if (fd >= 0)
	{
		result = ft_process_shift(shift, &str, line);
		if (result != 0)
			return (result);
		if (!ft_process_buff(fd, shift, &str))
			return (-1);
		if (!str)
			return (0);
		*line = str;
		return (1);
	}
	return (-1);
}
