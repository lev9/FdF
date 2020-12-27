/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 17:34:42 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *f)
{
	f->change = 1;
	if (key == keys(13, f))
		end(f);
	if (key == keys(19, f))
		text_to_window(f);
	zoom(f, key, 'k');
	move(f, key, 'k');
	set_altitude(f, key, 'k');
	change_projection(f, key, 'k');
	spin(f, key);
	set_theme(f, key, 'k');
	if (f->change == 1)
	{
		mlx_destroy_image(f->mlx, f->img);
		create_new_image(f);
	}
	return (0);
}

void	clickbutton2(int y, t_fdf *f)
{
	if (y > 200 && y < 213)
		set_altitude(f, 1, 'b');
	else if (y > 225 && y < 238)
		set_altitude(f, 2, 'b');
	else if (y > 265 && y < 278)
		change_projection(f, 1, 'b');
	else if (y > 290 && y < 303)
		change_projection(f, 2, 'b');
	else if (y > 315 && y < 328)
		spin(f, 99);
	else if (y > 380 && y < 393)
		set_theme(f, 1, 'b');
	else if (y > 405 && y < 418)
		set_theme(f, 2, 'b');
	else if (y > 495 && y < 508)
		f->mouse = 2;
	else if (y > 520 && y < 533)
		f->mouse = 1;
	else if (y > 545 && y < 558)
		f->mouse = 3;
	else if (y > 570 && y < 583)
		f->mouse = 4;
	else if (y > 595 && y < 608)
		f->mouse = 5;
}

void	click_button(int y, t_fdf *f)
{
	if (y > 20 && y < 33)
		zoom(f, 1, 'b');
	else if (y > 45 && y < 58)
		zoom(f, 2, 'b');
	else if (y > 85 && y < 98)
		move(f, 3, 'b');
	else if (y > 110 && y < 123)
		move(f, 1, 'b');
	else if (y > 135 && y < 148)
		move(f, 2, 'b');
	else if (y > 160 && y < 173)
		move(f, 4, 'b');
	else
		clickbutton2(y, f);
}

void	mouse_wheel(int button, t_fdf *f)
{
	if (button == 4)
	{
		if (f->mouse == 1)
			move(f, 2, 'b');
		else if (f->mouse == 3)
			move(f, 1, 'b');
		else if (f->mouse == 2)
			zoom(f, 1, 'b');
		else if (f->mouse == 4)
			set_altitude(f, 1, 'b');
		else if (f->mouse == 5)
			spin(f, 99);
	}
	else if (f->mouse == 1)
		move(f, 4, 'b');
	else if (f->mouse == 3)
		move(f, 3, 'b');
	else if (f->mouse == 2)
		zoom(f, 2, 'b');
	else if (f->mouse == 4)
		set_altitude(f, 2, 'b');
	else if (f->mouse == 5)
		spinback(f);
}

int		deal_mouse(int button, int x, int y, t_fdf *f)
{
	if (button == 4)
		mouse_wheel(4, f);
	if (button == 5)
		mouse_wheel(5, f);
	if (button == 1 && x > 15 && x < 30)
		click_button(y, f);
	if ((button == 1 || button == 2 || button == 3) && x > 200)
		f->mouse = button;
	mlx_destroy_image(f->mlx, f->img);
	create_new_image(f);
	return (0);
}
