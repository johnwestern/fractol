/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:09:23 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/25 19:57:09 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WDH 720
# define HGHT 720
# define GREEN 0x25FF50

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef union		u_color
{
	int				color;
	char			rgb[4];
}					t_color;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	int 			bpp;
	int 			sizeline;
	int				endian;
	int 			maxiter;
	int				offset_x;
	int				offset_y;
	double			image_x;
	double			image_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double 			zoom;
	char			*data;
	t_color			color;
}					t_data;

int					main(int ac, char **av);
int					key_hook(int keycode, t_data *e);
int					expose_hook(t_data *e);
void				put_usage_error(char *av);
void				put_malloc_error(void);
void				ft_init(void);
void				init_calc(t_data *e);
void				draw_mandelbrot(t_data *e);
void				set_color_pixel(int x, int y, t_data *e);
void				mandelbrot_calc(t_data *e, int x, int y);
void				mandelbrot_scale(t_data *e);

#endif
