/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:37:38 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:51:54 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

# define HEIGHT 900
# define WIDTH 1440

/*	Structure for the casting
** All the values for the raycasting
*/

typedef struct s_cast
{
	double		pd_x;
	double		pd_y;
	double		pd_x_strafe;
	double		pd_y_strafe;
	double		pa;
	double		ca;
	int			line_hight;
	int			line_offset;
	int			x_off;
	int			y_off;
	int			x_off_strafe;
	int			y_off_strafe;
	int			map_x;
	int			map_y;
	int			map_p;
	char		**map;
}				t_cast;

/*	Structure for the raycasting
** All the values for the raycasting
*/

typedef struct s_ray
{
	int		rays;
	int		n_of_rays;
	int		depoffield;
	double	ray_x;
	double	ray_y;
	double	ray_a;
	double	x_o;
	double	y_o;
	double	dist_h;
	double	dist_v;
	double	ver_x;
	double	ver_y;
	double	hor_x;
	double	hor_y;
	double	final_d;
	double	a_tan;
	double	n_tan;
	double	shade;
	double	tex_x;
	double	tex_y;
	double	ty_step;
	double	ty_off;
}	t_ray;

/*	Structure for the draw line
** All the values for the draw line
*/

typedef struct draw_line
{
	double		tx;
	double		ty;
	double		dy;
	double		fix_ra;
	int			delta_x;
	int			delta_y;
	int			direction_x;
	int			direction_y;
	int			error;
	int			two_times_error;
	int			pixel;
	int			begin_x;
	int			begin_y;
	int			end_x;
	int			end_y;
	int			color;
	int			x_off;
}	t_draw_line;

/*	Structure for the image
** All the values for the image
** Get all informations about the image
*/

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		x;
	int		y;
}	t_img;

/*	Structure for the textures
** All the values for the textures
** Get all informations about the textures
*/

typedef struct s_textures
{
	t_img	*wall_no;
	t_img	*wall_so;
	t_img	*wall_we;
	t_img	*wall_ea;
	t_img	*background;
	t_img	*minimap;
}	t_textures;

/*	Structure for the game
** All the values for the game
*/

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	int				dis_w;
	int				dis_h;
	double			pl_x;
	double			pl_y;
	t_cast			*cast;
	t_draw_line		*dl;
	t_ray			*ray;
	t_textures		*texture;
}	t_game;

/*	Structure for the map
** All the values for the map
*/

typedef struct s_map
{
	int		fd;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
	int		error;
	int		check;
	t_game	*game;
}				t_map;

/* All function
**	Is sorted by folder
*/

/* cb_check_file.c */
int		ft_check_extension(char *str);

/* cb_check_lines.c */
bool	ft_check_side(char **map, int j);
bool	ft_check_middle(char **map);
bool	ft_check_border(char **map);
bool	ft_check_current(char **map);
bool	ft_check_next(char **map);

/* cb_check_pos.c */
bool	ft_check_lines(char **map);
bool	ft_check_pos(char **map);
bool	ft_check_letters(char **map);
char	ft_player_pos(char **map);
int		ft_check_points(char c, char **map);

/* cb_check_rgb.c */
int		ft_check_rgb(t_map *map, char *line);
int		ft_check_rgb_range(char **rgb, char *line, int i, int j);
int		ft_get_rgb(t_map *map, char *id, char **rgb);
int		ft_check_floor(t_map *map);

/* cb_check_textures.c */
int		ft_get_texture(t_map *map, char *line, int k);
int		ft_check_xpm(t_map *map);

/* cb_map_check.c */
int		ft_get_map(t_map *map);
int		ft_check_map(t_map *map, char *line);
bool	ft_check_cor(char *line, int check);
char	*ft_check_nl(char *line, int map_fd);

/* cb_raycast.c */
void	ft_raycaster(t_game *game);
void	ft_set_value(t_game *game);
void	ft_replace_texture(t_game *game);
double	ft_get_distance(t_game *g, double bx, double by);
void	ft_set_ray_val(t_game *game);

/* cb_raycast2.c */
void	ft_set_honrizontal_val(t_game *game);
void	ft_line_honrizontal(t_game *game);
void	ft_honrizontal_wall(t_game *game);

/* cb_raycast3.c */
void	ft_set_vertical_val(t_game *game);
void	ft_line_vertical(t_game *game);
void	ft_vertical_wall(t_game *game);
void	ft_check_distance(t_game *game);

/* cb_raycast4.c */
void	ft_set_cos(t_game *game);
void	ft_set_render(t_game *game);
void	ft_draw_walls(t_game *game);

/* cb_render_texture.c */
int		ft_get_pixel(int x, int y, t_img *img);
long	ft_get_colors(t_game *game);
long	ft_get_we_ea_color(t_game *game);
long	ft_get_no_so_color(t_game *game);

/* cb_game_draw.c */
int		ft_draw_map(t_game *game, t_map *map);
void	ft_get_addr(t_textures *tex);
void	ft_draw_player(t_game *game, char **map);

/* cb_game_init */
void	ft_game(t_map *map);
int		ft_get_longuest(char **map);
void	ft_beggin(t_game *game, t_map *map);

/* cb_get_texture.c */
void	ft_get_draw_texture(t_game *game, t_map *map);

/* cb_init.c */
t_map	*ft_init_struct(char *path);
t_cast	*ft_init_cast(t_map *map);
t_ray	*ft_raycast_init(void);
void	ft_malloc_game(t_map *map);
t_draw_line	*ft_line_init(void);

/* cb_set_map.c */
char	**ft_setmap(int fd);
char	**ft_set(int fd);

/* ft_hooks */
int		ft_hooks(t_map *map);
int		ft_controls(int key, t_map *map);
void	ft_camera_move(t_game *game, int key);
void	ft_move_front_back(t_game *game, int key);
void	ft_move_vertical(t_game *game, int key);

/* cb_errors_management.c */
void	free_tab(char **tab);
void	ft_endgame(t_map *map);
void	ft_free_struct(t_map *map);
void	ft_destroy_img(t_game *game, int i);
void	ft_free_wall(t_map *map);

/* ft_exit.c */
void	ft_free_texture(t_map *map);
int		ft_exit(t_map *map);

/* cb_line_utils.c */
char	*ft_trim_space(char *line);
void	ft_init_null(t_map *map);
void	ft_malloc_img(t_textures *tex);

/* cb_move_utils.c */
void	ft_offset(t_game *game);
bool	ft_check_collision(char c);

/* cb_texture_utils.c */
long	ft_rgb_hex(int r, int g, int b);
void	ft_set_pixel(t_img *img, int max_x, int max_y, t_map *map);
void	mlx_put_pixel(t_img *img, int x, int y, long color);

/* cb_utils.c */
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *str1);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* cb_utils2.c */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);

/* cb_utils3.c */
bool	ft_isspace(char c);
int		ft_len_tab(char **tab);
int		ft_isdigit(int c);
bool	ft_is_close(char c);
int		ft_atoi(const char *str);

/* cb_utils4.c */
char	*ft_strjoin_free(const char *s1, const char *s2);
bool	ft_is_letters(char c);
void	ft_bzero(void *dst, size_t n);

/* ft_split.c */
char	**ft_split(char const *s, char c);

#endif
