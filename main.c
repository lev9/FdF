/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 17:39:26 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	end(t_fdf *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	free(f->int_arr);
	free(f->mlx);
	exit(0);
}

void	error2(t_fdf *f)
{
	ft_putstr_fd("not a valid map\n", 1);
	mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
	exit(0);
}

int		errormessage(int err)
{
	if (err == 1)
		ft_putstr_fd("not a valid file\n", 1);
	else if (err == 2)
		ft_putstr_fd("given argument is a directory\n", 1);
	return (-1);
}

void	start(int fd, t_fdf *f)
{
	f->arr = ft_strnew(0);
	read_file_to_string(fd, f);
	convert_to_int_array(f->arr, f);
	text_to_window(f);
	set_defaults(f);
	create_new_image(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 200, 0);
	mlx_hook(f->win, 2, 1L << 0, deal_key, f);
	mlx_mouse_hook(f->win, deal_mouse, f);
	mlx_loop(f->mlx);
}

int		main(int argc, char *argv[])
{
	t_fdf	*f;
	t_fdf	fdf;
	int		fd;
	char	*str;

	if (argc != 2)
	{
		ft_putstr_fd("give exactly 1 parameter please\n", 1);
		return (-1);
	}
	if (open(argv[1], O_DIRECTORY) != -1)
		return (errormessage(2));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (errormessage(1));
	str = ft_strjoin("FdF - ", argv[1]);
	f = &fdf;
	f->keys = 0;
	f->mlx = mlx_init();
	f->w = 1000;
	f->h = 800;
	f->win = mlx_new_window(f->mlx, f->w + 200, f->h, str);
	free(str);
	start(fd, f);
	return (0);
}
