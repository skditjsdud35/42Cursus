#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "../lib/include/get_next_line.h"
# include "../lib/include/libft.h"
# include "../mlx/mlx.h"

# define BLOCK_SIZE 64

# define ON_KEYDOWN 2
# define ON_DESTROY 17

# define KEY_ESC 53

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_collection
{
	t_pos				pos;
	int					is_collected;
	struct s_collection	*next;
}	t_collection;

typedef struct s_portal
{
	t_pos			pos;
	struct s_portal	*next;
}	t_portal;

typedef struct s_comp
{
	int				num_player_spon;
	int				num_collections;
	t_collection	collection_list;
	t_portal		portal_list;
}	t_comp;

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
}	t_map;

typedef struct s_image
{
	void	*collection_img;
	void	*portal_img;
	void	*player_img;
	void	*tile_img;
	void	*wall_img;
}	t_image;

typedef struct s_player
{
	t_pos	pos;
	int		num_collected;
	int		is_have_key;
	int		movement_cnt;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map_info;
	t_comp		map_comp;
	t_image		image;
	t_player	player;
}	t_game;

#endif
