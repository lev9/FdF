/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 12:53:26 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_buffer_y(t_fdf *f)
{
	f->y = 100 + f->placey;
	if (f->projection == 'd')
		f->y = f->y * 2 - (200 + f->placex);
}

void	get_buffer_x(t_fdf *f)
{
	f->x = 300 + f->placex;
	if (f->projection == 'd')
		f->x = f->x + 100 + f->placey;
}

void	fill_buffer(t_fdf *f)
{
	int	index;

	f->drawn = 0;
	get_buffer_y(f);
	index = 0;
	while (index < f->mapsize - 1)
	{
		get_buffer_x(f);
		while (f->int_arr[index] != 10000)
		{
			f->num = f->int_arr[index];
			check_neighbors(f, index);
			f->x += f->zoom;
			index++;
		}
		f->y = f->y + f->zoom;
		index += 1;
	}
}

void	create_new_image(t_fdf *f)
{
	int	p_bits;
	int	line_pix;
	int	endian;

	f->img = mlx_new_image(f->mlx, f->w, f->h);
	f->buffer = (int*)mlx_get_data_addr(f->img, &p_bits, &line_pix, &endian);
	f->line_pix = line_pix / 4;
	fill_buffer(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 200, 0);
}

void	set_defaults(t_fdf *f)
{
	f->placex = 0;
	f->placey = 0;
	f->zoom = 300 / f->maplines;
	if (f->zoom % 2 != 0)
		f->zoom++;
	f->projection = 'd';
	f->theme = 1;
	f->alt = 1;
	f->spinx = 0.0;
	f->spiny = 0.0;
}
