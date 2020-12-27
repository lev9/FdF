/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:52:16 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:52:59 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key1b(int c)
{
	if (c == 10)
		return (21);
	if (c == 11)
		return (23);
	if (c == 12)
		return (22);
	if (c == 13)
		return (53);
	if (c == 14)
		return (8);
	if (c == 15)
		return (6);
	if (c == 16)
		return (7);
	if (c == 17)
		return (9);
	if (c == 18)
		return (11);
	if (c == 19)
		return (17);
	return (0);
}

int		key1a(int c)
{
	if (c == 1)
		return (26);
	if (c == 2)
		return (28);
	if (c == 3)
		return (123);
	if (c == 4)
		return (126);
	if (c == 5)
		return (124);
	if (c == 6)
		return (125);
	if (c == 7)
		return (18);
	if (c == 8)
		return (19);
	if (c == 9)
		return (20);
	return (key1b(c));
}

int		key2b(int c)
{
	if (c == 10)
		return (52);
	if (c == 11)
		return (53);
	if (c == 12)
		return (54);
	if (c == 13)
		return (65307);
	if (c == 14)
		return (99);
	if (c == 15)
		return (122);
	if (c == 16)
		return (120);
	if (c == 17)
		return (118);
	if (c == 18)
		return (98);
	if (c == 19)
		return (116);
	return (0);
}

int		key2a(int c)
{
	if (c == 1)
		return (55);
	if (c == 2)
		return (56);
	if (c == 3)
		return (65361);
	if (c == 4)
		return (65362);
	if (c == 5)
		return (65363);
	if (c == 6)
		return (65364);
	if (c == 7)
		return (49);
	if (c == 8)
		return (50);
	if (c == 9)
		return (51);
	return (key2b(c));
}

int		keys(int c, t_fdf *f)
{
	if (f->keys == 1)
		return (key1a(c));
	return (key2a(c));
}
