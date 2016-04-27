/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:09:23 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/28 00:15:03 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WDH 1680
# define HGHT 945
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

typedef struct		s_cplx
{
	float			x;
	float			y;
}					t_cplx;

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
	float 			zoom;
	char			*data;
	t_color			color;
}					t_data;

int					main(int ac, char **av);
int					key_hook(int keycode, t_data *e);
int					expose_hook(t_data *e);
void				put_usage_error(char *av);
void				put_malloc_error(void);
void				ft_init(t_data *e);
void				draw_mandelbrot(t_data *e);
void				set_pixel(int x, int y, t_data *e);
void				set_i_color(int i, t_data *e);

#endif
