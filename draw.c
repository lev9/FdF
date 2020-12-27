/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 17:14:09 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *f, t_point *p)
{
	p->color = p->num;
	while (p->steps >= 0)
	{
		p->cury = (p->oldy - p->num - round(p->y_jump));
		p->cury += (f->h / 2 - p->cury) * f->spinx;
		p->cury *= f->line_pix;
		p->curx = p->oldx + round(p->x_jump);
		p->curx += (f->w / 2 - p->curx) * f->spiny;
		p->pix = p->cury + p->curx;
		if (p->curx > 0 && p->curx < f->w - 1 && p->pix >= 0 &&
		p->pix / f->w < f->h && (f->buffer[p->pix] == 0 ||
		f->projection == 'd'))
		{
			f->buffer[p->pix] = color(f, p->color);
			f->drawn++;
		}
		p->steps--;
		p->x_jump += p->x_step;
		p->y_jump += p->y_step;
		if (p->num > p->next)
			p->color--;
		else if (p->num < p->next)
			p->color++;
	}
}

void	get_step_lengths(t_fdf *f, t_point *p)
{
	int	x_len;
	int	y_len;

	p->oldx = f->x;
	p->oldy = f->y;
	if (f->projection == 'd')
	{
		p->oldx = (p->oldx - p->oldy);
		p->oldy = (f->x + p->oldy) / 2;
	}
	x_len = p->next_x - p->oldx;
	y_len = p->next_y - p->oldy;
	if (abs(x_len) > abs(y_len))
		p->steps = abs(x_len);
	else
		p->steps = abs(y_len);
	p->x_step = x_len / (float)p->steps;
	p->y_step = y_len / (float)p->steps;
}

void	get_new_x_y(t_fdf *f, t_point *p, int direction)
{
	if (f->projection == 'p' && direction == 1)
	{
		p->next_x = f->x + f->zoom - (p->next - p->num);
		p->next_y = f->y + (p->num - p->next);
	}
	if (f->projection == 'p' && direction == 2)
	{
		p->next_x = f->x + (p->num - p->next);
		p->next_y = f->y - f->zoom - (p->next - p->num);
	}
	if (f->projection == 'd' && direction == 1)
	{
		p->next_x = f->x + f->zoom - f->y;
		p->next_y = (f->x + f->y) / 2 - (f->zoom / 2 - (p->next - p->num));
	}
	if (f->projection == 'd' && direction == 2)
	{
		p->next_x = f->x - f->y - f->zoom;
		p->next_y = (f->x + f->y) / 2 - (f->zoom / 2 - (p->next - p->num));
	}
}

void	handle_new_line(t_fdf *f, int next, int direction)
{
	t_point	point;
	t_point	*p;
	int		swap;
	int		swapy;

	swap = f->x;
	swapy = f->y;
	p = &point;
	p->num = f->num * f->zoom / 10.0 * f->alt;
	p->next = next * f->zoom / 10.0 * f->alt;
	if (f->projection == 'p')
	{
		f->x -= p->num;
		f->y += p->num * 2;
	}
	get_new_x_y(f, p, direction);
	get_step_lengths(f, p);
	f->x = swap;
	f->y = swapy;
	p->x_jump = 0;
	p->y_jump = 0;
	draw_line(f, p);
}

void	check_neighbors(t_fdf *f, int index)
{
	int		right;
	int		down;

	if (f->int_arr[index + 1] != 10000)
	{
		right = f->int_arr[index + 1];
		if (index + 1 < f->mapsize - 1)
			handle_new_line(f, right, 1);
	}
	if ((f->mapwidth + 1) * (f->maplines - 1) > index)
	{
		down = f->int_arr[index + f->mapwidth + 1];
		if (down != 10000)
			handle_new_line(f, down, 2);
	}
}
