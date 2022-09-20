#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "X.h"

typedef struct img{
		unsigned char *data;
		int w;
		int h;
		char *tx;
		int	sline;
		void *image;
}		s_img;

typedef struct sprite{
	double posx;
	double posy;
	double perpwalldist;
	struct sprite	*next;
}		s_sprite;

typedef struct file{
	s_img NO;
	s_img SO;
	s_img EA;
	s_img WE;
	s_img sprite;
	s_sprite *info;
	s_sprite *saveinfo;
	void *mlx_ptr;
	void *win_ptr;
    int res[2];
    int rgbFL[3];
    int rgbRO[3];
    char *map;

	double planex;
	double planey;
	double camx;
	double raydirx;
	double raydiry;
	int mapx;
	int mapy;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	int stepx;
	int stepy;
	int Lmap;
	int Hmap;
	int hit;
	int side;
	void *image;
	double movespeed;
	double	rotspeed;
	double	pos[2];
	double	dir[2];
	int lineheight;
	int drawstart;
	int drawend;
	int savehit[1000];
	double *saveperpdist;
	double **savespritepos;
	int save;
	int savelst;
	int n;
	double wallx;
	int		sline;
	char	*dataimg;
}		s_param;

/////// PARSING //////
void    init_param(s_param *param);
void	set_pos(s_param *param);
void	get_map(s_param *param, char *line, int read);
void	get_rgb_fc(s_param *param, char *line);
void	get_sprite(s_param *param, char *line);
void	get_wall(s_param *param, char *line);
void	get_res(s_param *param, char *line);
/////// PARSING //////

/////// GET DATA IMG  ///////
char	*ft_nosmt(char *str, char c);
void	ft_get_data_img(s_param *param, s_img *img);
int		print_img(s_param *param, s_img *img);
int		nowall(s_param param, int neg, double vecx, double vecy);
/////// GET DATA IMG  ///////

/////// EVENTS & MOVE ///////
int		moveforward(s_param *param);
int		movebackward(s_param *param);
int		shiftright(s_param *param);
int		shiftleft(s_param *param);
int		rotate(int key, s_param *param);
int		gestevent(s_param *param);
/////// EVENTS & MOVE ///////

/////// ALGO CUB3D ///////
int		print(s_param *param);
void	init_paramcub(s_param *param, int x, int w);
void	set_side(s_param *param);
void	isitwall(s_param *param, int x);
void	set_draw(s_param *param);
/////// ALGO CUB3D ///////

/////// DRAW IMG ///////
void	draw_floor(s_param *param, char *data, int *tab, int *tin);
void	draw_sky(s_param *param, char *data, int *tab, int *tin);
void	draw_wall(s_param *param, char *data, int *tab, int *tin);
void	draw_sprite(s_param *param);
/////// DRAW IMG ///////

/////// UTILS FOR LST ///////
s_sprite	*ft_lstlastprint(s_sprite *lst);
s_sprite	*ft_lstnews(void);
void		ft_lstclears(s_sprite **lst);
int			ft_lstsizes(s_sprite *lst);
double		get_pos_lst(s_sprite *lst, char c, int i);
/////// UTILS FOR LST ///////

#endif