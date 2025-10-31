#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 800

# define ESC_KEY 65307
# define DESTROY_NOTIFY 17

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*fractal_type;
}	t_data;

void	print_usage(void);
int		validate_args(int argc, char **argv);
int		init_fractal(t_data *data);
int		close_window(t_data *data);
int		handle_keypress(int keycode, t_data *data);

#endif
