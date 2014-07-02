/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libwf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 14:48:41 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 21:16:15 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBWF_H
# define LIBWF_H
# define BUFF_SIZE 8

# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_tab
{
	int				i;
	int				j;
	int				start;
	int				nb;
}					t_tab;

typedef struct		s_env
{
	char			status;
	void			*mlx;
	void			*win;
	char            **map;
	int				*size_map;
	int             height;
	char			**str;
	int				nb_map;
	float           x;
	float			y;
	float			angle;
	void			*img_ptr;
	char			*data;
	int				bitpp;
	int				size_l;
	int				endian;
	int				color[6];
	int				typecolor1;
	int				typecolor2;
}					t_env;

char			*ft_charsplit(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(unsigned int size);
char			*ft_strnjoin(char const *s1, char const *s2, int len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_modif_place(t_env *e, float tmpx, float tmpy);
void			ft_color(t_env *e);
void			ft_wall_color(t_env *, float v_sin, float v_cos);
void			wolf_3d(char *str, t_env *e);
void			ft_error(void);
void			ft_error_map(void);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memalloc(unsigned int size);
void			ft_bzero(void *s, unsigned int n);
void			ft_nbrsplit_first_line(char const *s, int **tab);
void			ft_print_wall(t_env *e, float distance, int x);
int				get_next_line(int const fd, char **line);
int				put_to_img(t_env *e, int x, int y, int color);
int				ft_print_wall_color(int color1, int color2, t_env *e);
int				sky(t_env *e);
int				floorz(t_env *e);
int				expose_loop(t_env *e);
int				button(int keycode, t_env *e);
int				ft_atoi(const char *str);
int				ft_square(int nbr);
int				ft_power(int nbr, int power);
int				ft_search_hypotenuse(int a, int b);
int				ft_search_side(int a, int b);
int				wall(t_env *e);
unsigned int	ft_strlen(const char *s);
void			ft_create_map(char *av, t_env *e);
t_env			ft_ray_init(t_env e);
float			ft_distance(t_env *e, float angle);

#endif /* !LIBWF_H */
