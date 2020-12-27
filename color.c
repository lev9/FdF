/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_g(int n)
{
	int	r;
	int	g;
	int	b;

	if (n >= 0 && n < 64)
	{
		r = 255;
		g = n * 4;
		b = 0;
	}
	else
	{
		r = 0;
		g = 255 - (n * 4 - 192 * 4);
		b = 255;
	}
	return (0 | (r << 16) | (g << 8) | b);
}

int		get_r(int n)
{
	int	r;
	int	g;
	int	b;

	if (n >= 64 && n < 128)
	{
		r = 255 - (n * 4 - 64 * 4);
		g = 255;
		b = 0;
	}
	else
	{
		r = n * 4 - 256 * 4;
		g = 0;
		b = 255;
	}
	return (0 | (r << 16) | (g << 8) | b);
}

int		get_b(int n)
{
	int	r;
	int	g;
	int	b;

	if (n >= 128 && n < 192)
	{
		r = 0;
		g = 255;
		b = n * 4 - 128 * 4;
	}
	else
	{
		r = 255;
		g = 0;
		b = 255 - (n * 4 - 320 * 4);
	}
	return (0 | (r << 16) | (g << 8) | b);
}

int		rb(int n)
{
	n = 180 + n * 0.3;
	if (n < 0)
		n = -n;
	if (n > 320)
		n %= 320;
	if ((n >= 0 && n < 64) || (n >= 192 && n < 256))
		return (get_g(n));
	else if ((n >= 64 && n < 128) || (n >= 256 && n < 320))
		return (get_r(n));
	else
		return (get_b(n));
}

int		color(t_fdf *f, int n)
{
	if (f->theme == 1)
		return (0xFFFFFF);
	else
		return (rb(n));
}
