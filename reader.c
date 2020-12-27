/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 13:32:23 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	skip(char *line, t_fdf *f)
{
	if (line[f->i] == ',')
	{
		while (line[f->i] && line[f->i + 1] != ' ' && line[f->i + 1] != '\0')
			f->i++;
		f->length++;
		if (f->maplines == 0)
			f->mapwidth++;
		f->i++;
	}
}

void	meazure_line(char *line, t_fdf *f)
{
	f->i = 0;
	f->length = 0;
	while (line[f->i] != '\0')
	{
		skip(line, f);
		if (line[f->i] == '\0')
			break ;
		if (ft_isdigit(line[f->i]) && (line[f->i + 1] == '\0' || line[f->i + 1]
		== ' '))
		{
			f->length++;
			if (f->maplines == 0)
				f->mapwidth++;
		}
		if ((!(ft_isdigit(line[f->i]))) && line[f->i] != ' ' &&
		line[f->i] != '-')
			error2(f);
		f->i++;
	}
	if (f->maplines > 0 && f->mapwidth < f->length)
		f->last_length++;
	if ((f->maplines > 0 && (f->mapwidth - f->length > 0 || f->length -
	f->mapwidth > 1)) || (f->maplines == 0 && f->mapwidth == 0))
		error2(f);
}

void	read_file_to_string(int fd, t_fdf *f)
{
	char	*line;
	char	*temp;

	f->maplines = 0;
	f->mapsize = 0;
	f->last_length = 0;
	while (get_next_line(fd, &line))
	{
		if (f->last_length > 0)
			error2(f);
		if (f->maplines == 0)
			f->mapwidth = 0;
		meazure_line(line, f);
		f->mapsize += f->mapwidth + 1;
		temp = ft_strjoin(f->arr, line);
		free(f->arr);
		f->arr = temp;
		temp = ft_strjoin(f->arr, "N");
		free(f->arr);
		f->arr = temp;
		f->maplines++;
		free(line);
	}
	if (f->mapsize == 0 || (f->mapwidth == 1 && f->maplines == 1))
		error2(f);
}

int		handle_nbr(char *str, t_fdf *f, int i, int a)
{
	int		num;
	int		neg;

	num = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i] != 'N')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num >= 999)
		{
			num = 999;
			while (ft_isdigit(str[i]) && str[i] != 'N')
				i++;
		}
	}
	f->int_arr[a] = num * neg;
	return (i);
}

void	convert_to_int_array(char *str, t_fdf *f)
{
	int		i;
	int		a;

	f->int_arr = (int*)malloc(sizeof(int) * (f->mapsize + 1));
	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			while (str[i] != 'N' && str[i] != ' ')
				i++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i] == 'N')
		{
			f->int_arr[a] = 10000;
			i++;
		}
		else
			i = handle_nbr(str, f, i, a);
		a++;
	}
	free(f->arr);
}
