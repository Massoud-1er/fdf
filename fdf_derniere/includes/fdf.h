/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:34:40 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 23:11:13 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/*
** Keys macro
*/
# define ESC 53
# define AR_L 123
# define AR_R 124
# define AR_U 126
# define AR_D 125
# define PLUS 69
# define MINUS 78
# define K_NP_1	83
# define K_NP_2	84
# define K_NP_3	85
# define K_NP_4	86
# define K_NP_5	87
# define K_NP_6	88
# define K_NP_7	89
# define K_NP_8	91
# define K_NP_9	92
# define SPACE 49
# define CHEV_L 43
# define CHEV_R 47
# define TAB 48

/*
**Mouse macro
*/
# define CLICK_L 1
# define CLICK_R 2
# define CLICK_U 4
# define CLICK_D 5

/*
** Macro Numbers
*/

# define MAX_WIN_X 2560
# define MAX_WIN_Y 1440
# define MIN_WIN_X 450
# define MIN_WIN_Y 300
# define MAX_MULTI 40
# define MIN_MULTI 6
# define ZOOM_MAX 20
# define ZOOM_MIN 0

/*
** Colors
*/

# define GREEN 0x008000
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define PURPLE 0x800080
# define ORANGE 0xFFA500
# define MARS_COLOR 1
# define PYRA_COLOR 2
# define RAINBOW_COLOR 3
# define EARTH_COLOR 4

/*
** Structures
*/

typedef struct	s_modif
{
	int			mod_x;
	int			mod_y;
	int			mod_z;
	int			zoom;
	size_t		color;
	int			switch_proj;
	int			mirror;
}				t_modif;

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef	struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			line_x;
	int			line_y;
	int			line_z;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
}				t_line;

typedef struct	s_img
{
	void		*ptr;
	char		*image;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_args
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*file;
	int			diff;
	t_point		*all_int;
	t_modif		modif;
	t_img		*image;
	int			win_x;
	int			win_y;
	int			nb_lines;
	int			x_pos;
}				t_args;

/*
** Functions
*/

int				count_int(char *file, int nb);
t_point			*parse(t_args *args);
int				make_line(t_point *int_all, t_args args, t_img *img);
int				print_line(t_args args, t_line line, t_img *img);
int				error(int i);
int				mouse_hook(int button, int x, int y, t_args *args);
int				key_hooks(int key, void *args);
t_point			*malloc_tab(int nb);
size_t			mars_color(int z, int max_z);
int				zoom(int key, t_args *args);
int				depth(int key, t_args *args);
void			reverse(t_args *args);
int				move(int key, t_args *args);
void			put_exit(void);
void			put_exit_free(t_args *args);
void			free_all(t_args *args);
void			set_all(t_point *i, t_point *f, t_args args);

/*
** Function colors
*/

size_t			fcolor(int z, int diff_z, size_t color_ref);

/*
**	images functions
*/

void			pixel_img(size_t *image, int x, int y, int color);
t_img			*create_image(t_args args);
void			pixel_to_img(t_img *img, int x, int y, int color);
void			clear_img(t_img *img);

#endif
