#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../lib/include/get_next_line/get_next_line.h"
#include "../lib/include/libft/libft.h"

# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_RELEASE    3

# define KEY_ESC    53
# define KEY_W  13
# define KEY_A  0
# define KEY_S  1
# define KEY_D  2

typedef struct s_param{
    int x;
    int y;
}   t_param;

typedef struct s_image{
    void    *wall;
    void    *tile;
    void    *coin;
    void    *player;
    void    *exit;
}   t_img;

typedef struct s_game{
    int width;
    int height;
    char *total_line;
}   t_game;

void    param_init(t_param *param)
{
    param->x = 0;
    param->y = 0;
}

int key_press(int keycode, t_param *param)
{
    if (keycode == KEY_W)
        (param->y)++;
    else if (keycode == KEY_S)
        (param->y)--;
    else if (keycode == KEY_D)
        (param->x++);
    else if (keycode == KEY_A)
        (param->x--);
    else if (keycode == KEY_ESC)
        exit(0);
    printf("x : %d y : %d\n",param->x, param->y);
    return (0);
}

void    init_img(void   *mlx_ptr, void  *win_ptr)
{
    t_img img;
    int img_width;
    int img_height;

    img.wall = mlx_xpm_file_to_image(mlx_ptr, "./image/wall.xpm", &img_width, &img_height);
    img.tile = mlx_xpm_file_to_image(mlx_ptr, "./image/white.xpm", &img_width, &img_height);
    img.coin = mlx_xpm_file_to_image(mlx_ptr, "./image/coin.xpm", &img_width, &img_height);
    img.player = mlx_xpm_file_to_image(mlx_ptr, "./image/player.xpm", &img_width, &img_height);
    img.exit = mlx_xpm_file_to_image(mlx_ptr, "./image/exit.xpm", &img_width, &img_height);
    
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.wall, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.tile, 32, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.coin, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.player, 0, 32);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.exit, 32, 32);
}

char	*_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = 0;
	j = 0;
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	str = malloc (s1_len + s2_len + 1);
	if (!str)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void    read_map(char *filename)
{
    int fd;
    char    *line;
    t_game  game;

    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    game.width = ft_strlen(line) - 1;
    game.height = 0;
    game.total_line = ft_strdup(line);
    free(line);
    if (fd < 0)
        printf("Error!\n");
    while (line)
    {
        (game.height)++;
        line = get_next_line(fd);
        game.total_line = _ft_strjoin(game.total_line, line);
    }
	close(fd);
	printf("%s\n", game.total_line);
}

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_param param;


    param_init(&param);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so long");
    read_map("map.ber");
    init_img(mlx_ptr,win_ptr);
    mlx_hook(win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
    mlx_loop(mlx_ptr);
}
