/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:09:23 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/23 16:26:44 by jdavin           ###   ########.fr       */
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
	int 			endian;
	char			*data;
}					t_data;

int					main(int ac, char **av);
int					key_hook(int keycode, t_data *e);
int					expose_hook(t_data *e);
void				put_usage_error(char *av);
void				put_malloc_error(void);
void				ft_init(void);
void				ft_test(t_data *e);

#endif
