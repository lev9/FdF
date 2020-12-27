/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 17:31:51 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	spin(t_fdf *f, int key)
{
	if (key == 99)
		key = keys(14, f);
	if ((key == keys(14, f) && f->spiny <= 1.8 && f->spinx <= 0.2) ||
	(key == keys(15, f) && f->spiny < 1.8))
		f->spiny += 0.2;
	if ((key == keys(14, f) && f->spiny >= 1.8 && f->spinx <= 1.8) ||
	(key == keys(17, f) && f->spinx < 1.8))
		f->spinx += 0.2;
	if ((key == keys(14, f) && f->spinx >= 1.8 && f->spiny >= 0.2) ||
	(key == keys(16, f) && f->spiny > 0.2))
		f->spiny -= 0.2;
	if ((key == keys(14, f) && f->spiny <= 0.2 && f->spinx >= 0.2) ||
	(key == keys(18, f) && f->spinx > 0.2))
		f->spinx -= 0.2;
}

void	spinback(t_fdf *f)
{
	if (f->spinx >= 0.2 && f->spiny >= 1.8)
		f->spinx -= 0.2;
	if (f->spinx <= 0.2 && f->spiny >= 0.2)
		f->spiny -= 0.2;
	if (f->spiny <= 0.2 && f->spinx <= 1.8)
		f->spinx += 0.2;
	if (f->spinx >= 1.8 && f->spiny <= 1.8)
		f->spiny += 0.2;
}

void	button(t_fdf *f, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 13)
	{
		i = 0;
		while (i < 13)
		{
			if (!(j == 0 && (i == 0 || i == 12))
			&& !(j == 12 && (i == 0 || i == 12)))
				mlx_pixel_put(f->mlx, f->win, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	set_buttons(t_fdf *f)
{
	int	a;
	int	b;

	a = 0x705b8c;
	b = 0xc49ff5;
	button(f, 15, 20, a);
	button(f, 15, 45, a);
	button(f, 15, 85, a);
	button(f, 15, 110, a);
	button(f, 15, 135, a);
	button(f, 15, 160, a);
	button(f, 15, 200, a);
	button(f, 15, 225, a);
	button(f, 15, 265, a);
	button(f, 15, 290, a);
	button(f, 15, 315, a);
	button(f, 15, 380, a);
	button(f, 15, 405, a);
	button(f, 15, 495, b);
	button(f, 15, 520, b);
	button(f, 15, 545, b);
	button(f, 15, 570, b);
	button(f, 15, 595, b);
}

void	text_to_window(t_fdf *f)
{
	int		i;

	i = 0;
	i = f->keys * 15;
	mlx_string_put(f->mlx, f->win, 45, 30 - i, 0xfffafa, "zoom in      7");
	mlx_string_put(f->mlx, f->win, 45, 55 - i, 0xfffafa, "zoom out     8");
	mlx_string_put(f->mlx, f->win, 45, 95 - i, 0xfffafa, "right       ->");
	mlx_string_put(f->mlx, f->win, 45, 120 - i, 0xfffafa, "left");
	mlx_string_put(f->mlx, f->win, 45, 145 - i, 0xfffafa, "up");
	mlx_string_put(f->mlx, f->win, 45, 170 - i, 0xfffafa, "down");
	mlx_string_put(f->mlx, f->win, 45, 210 - i, 0xfffafa, "high         1");
	mlx_string_put(f->mlx, f->win, 45, 235 - i, 0xfffafa, "low          2");
	mlx_string_put(f->mlx, f->win, 45, 275 - i, 0xfffafa, "parallel     3");
	mlx_string_put(f->mlx, f->win, 45, 300 - i, 0xfffafa, "dimetric     4");
	mlx_string_put(f->mlx, f->win, 45, 325 - i, 0xfffafa, "spin         c");
	mlx_string_put(f->mlx, f->win, 25, 350 - i, 0xfffafa, "z | x    v | b");
	mlx_string_put(f->mlx, f->win, 45, 390 - i, 0xfffafa, "white        5");
	mlx_string_put(f->mlx, f->win, 45, 415 - i, 0xfffafa, "color        6");
	mlx_string_put(f->mlx, f->win, 25, 475 - i, 0xfffafa, "mouse wheel:  ");
	mlx_string_put(f->mlx, f->win, 45, 505 - i, 0xfffafa, "zoom");
	mlx_string_put(f->mlx, f->win, 45, 530 - i, 0xfffafa, "vertical");
	mlx_string_put(f->mlx, f->win, 45, 555 - i, 0xfffafa, "horizontal");
	mlx_string_put(f->mlx, f->win, 45, 580 - i, 0xfffafa, "high | low");
	mlx_string_put(f->mlx, f->win, 45, 605 - i, 0xfffafa, "spin");
	set_buttons(f);
}
