/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef	struct	s_fdf
{
	int		mapwidth;
	void	*mlx;
	void	*win;
	void	*img;
	int		h;
	int		w;
	int		fd;
	char	*arr;
	int		*int_arr;
	int		mapsize;
	int		maplines;
	int		length;
	int		last_length;
	int		*buffer;
	int		line_pix;
	int		num;
	int		placey;
	int		placex;
	int		x;
	int		y;
	int		zoom;
	int		alt;
	char	projection;
	int		proj_x;
	int		proj_y;
	int		mouse;
	int		theme;
	double	spinx;
	double	spiny;
	int		drawn;
	int		keys;
	int		i;
	int		change;
}				t_fdf;

typedef	struct	s_point
{
	int		num;
	int		next;
	int		next_x;
	int		next_y;
	int		oldx;
	int		oldy;
	int		curx;
	int		cury;
	int		steps;
	double	x_step;
	double	y_step;
	double	x_jump;
	double	y_jump;
	int		pix;
	int		color;
}				t_point;

/*
**	main.c
*/
void			end(t_fdf *f);
void			error2(t_fdf *f);
int				errormessage(int err);
void			start(int fd, t_fdf *f);
int				main(int argc, char *argv[]);

/*
** keys.c
*/
int				keys(int c, t_fdf *f);
int				key1b(int c);
int				key1a(int c);
int				key2b(int c);
int				key2a(int c);

/*
**	reader.c
*/

void			skip(char *line, t_fdf *f);
void			meazure_line(char *line, t_fdf *f);
void			read_file_to_string(int fd, t_fdf *f);
int				handle_nbr(char *str, t_fdf *f, int i, int a);
void			convert_to_int_array(char *str, t_fdf *f);

/*
**	draw.c
*/
void			draw_line(t_fdf *f, t_point *p);
void			get_step_lengths(t_fdf *f, t_point *p);
void			get_new_x_y(t_fdf *f, t_point *p, int direction);
void			handle_new_line(t_fdf *f, int next, int direction);
void			check_neighbors(t_fdf *f, int index);

/*
**	image.c
*/
void			get_buffer_y(t_fdf *f);
void			get_buffer_x(t_fdf *f);
void			fill_buffer(t_fdf *f);
void			create_new_image(t_fdf *f);
void			set_defaults(t_fdf *f);

/*
**      actions.c
*/
void			spin(t_fdf *f, int key);
void			spinback(t_fdf *f);
void			button(t_fdf *fdf, int x, int y, int color);
void			set_buttons(t_fdf *f);
void			text_to_window(t_fdf *f);

/*
**	actions2.c
*/
void			zoom(t_fdf *f, int key, char user);
void			move(t_fdf *f, int key, char uesr);
void			set_altitude(t_fdf *f, int choice, char user);
void			change_projection(t_fdf *f, int key, char user);
void			set_theme(t_fdf *f, int key, char user);

/*
**	user.c
*/
int				deal_key(int key, t_fdf *f);
void			cilck_button2(int y, t_fdf *f);
void			click_button(int y, t_fdf *f);
void			mouse_wheel(int button, t_fdf *f);
int				deal_mouse(int button, int x, int y, t_fdf *f);

/*
**	color.c
*/
int				get_r(int n);
int				get_g(int n);
int				get_b(int n);
int				rb(int n);
int				color(t_fdf *f, int n);

#endif
