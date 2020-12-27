/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:53:32 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_fdf *f, int key, char user)
{
	if ((key == 1 && user == 'b') || (key == keys(1, f) && user == 'k'))
	{
		if (f->zoom < 300)
		{
			f->zoom += 2;
			if (f->projection == 'p')
				f->placex -= 10;
		}
		else
			f->change = 0;
	}
	if ((key == 2 && user == 'b') || (key == keys(2, f) && user == 'k'))
	{
		if (f->zoom > -300)
		{
			f->zoom -= 2;
			if (f->projection == 'p')
				f->placex += 10;
		}
		else
			f->change = 0;
	}
}

void	move(t_fdf *f, int key, char user)
{
	if (((key == keys(3, f) && user == 'k') || (key == 1 && user == 'b')) &&
	!(f->placex < 0 && f->drawn < 1))
		f->placex -= 10;
	if (((key == keys(4, f) && user == 'k') || (key == 2 && user == 'b')) &&
	!(f->placey < 0 && f->drawn < 1))
	{
		f->placey -= 10;
		if (f->projection == 'd')
			f->placex -= 5;
	}
	if (((key == keys(5, f) && user == 'k') || (key == 3 && user == 'b')) &&
	!(f->placex > 0 && f->drawn < 1))
		f->placex += 10;
	if (((key == keys(6, f) && user == 'k') || (key == 4 && user == 'b')) &&
	!(f->placey > 0 && f->drawn < 1))
	{
		f->placey += 10;
		if (f->projection == 'd')
			f->placex += 5;
	}
}

void	set_altitude(t_fdf *f, int choice, char user)
{
	if ((choice == 1 && user == 'b') || (choice == keys(7, f) && user == 'k'))
	{
		if (f->alt < 300)
			f->alt++;
		else
			f->change = 0;
	}
	if ((choice == 2 && user == 'b') || (choice == keys(8, f) && user == 'k'))
	{
		if (f->alt > -300)
			f->alt--;
		else
			f->change = 0;
	}
}

void	change_projection(t_fdf *f, int key, char user)
{
	if ((key == 2 && user == 'b') || (key == keys(10, f) && user == 'k'))
		f->projection = 'd';
	if ((key == 1 && user == 'b') || (key == keys(9, f) && user == 'k'))
		f->projection = 'p';
}

void	set_theme(t_fdf *f, int key, char user)
{
	if ((key == 1 && user == 'b') || (key == keys(11, f) && user == 'k'))
		f->theme = 1;
	if ((key == 2 && user == 'b') || (key == keys(12, f) && user == 'k'))
		f->theme = 2;
}
