/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:09:23 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/01 13:07:32 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WDH 1600
# define HGHT 900
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

typedef struct 		s_flcl
{
	float			a;
	float			b;
	float			c;
	float			l;
}					t_flcl;
	

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	int				mitr;
	int				ato;
	int 			hud;
	int				start;
	float			offset_x;
	float			mouse_x;
	float			offset_y;
	float			mouse_y;
	float			zoom;
	char			*data;
	t_color			color;
}					t_data;

int					main(int ac, char **av);
int					key_hook(int keycode, t_data *e);
int					mouse_hook(int button, int x, int y, t_data *e);
void				put_usage_error(char *av);
void				put_malloc_error(void);
void				init(t_data *e);
void				draw_mandelbrot(t_data *e);
void				set_i_color(int i, t_data *e);
void				display_str(t_data *e);

#endif
