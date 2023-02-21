# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>

#include "minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw(int i, int iend, int j, int jstart, int jend, t_data img)
{
	while (i < iend)
	{
		while (jstart < jend)
			my_mlx_pixel_put(&img, i, jstart++, 0x000000FF);
		jstart = j;
		i++;	
	}
}

int change(int i, int vi, int iend, int viend, int j, int vj, int jstart, int vjstart, int jend, int vjend, int flag)
{
	if (!flag)
		return i += vi;
	else if (flag == 1)
		return iend += viend;
	else if (flag == 2)
		return j += vj;
	else if (flag == 3)
		return jstart += vjstart;
	return jend += vjend;
}
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 720, "Siuu");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int i = 50;
	int iend = 150;
	int j = 50;
	int jstart = j;
	int jend = 75;
	// S
	draw(i, iend, j, jstart, jend, img);
	draw(i, iend - 75, j + 25, jstart + 25, jend + 50, img);
	draw(i, iend, j + 75, jstart, jend + 75, img);
	draw(i + 75, iend, j + 100, jstart + 100, jend + 150, img);
	draw(i, iend, j + 150, jstart + 150, jend + 150, img);
	// I
	draw(175, 200, 50, 50, 225, img);
	// U
	i = 225;
	iend = 250;
	jend = 225;
	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	i = 350;
	iend = 375;
	jend = 225;

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	i = 475;
	iend = 500;
	jend = 225;

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	i = 600;
	iend = 625;
	jend = 225;

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img);
	draw(i + 75, iend + 75, j, jstart, jend, img);

	// !

	i = 750;
	iend = 775;
	jend = 175;

	draw(i, iend, j, jstart, jend, img);
	draw(i, iend, j + 150, jstart + 150, jend + 50, img);
	i += 50;
	iend += 50;
	draw(i, iend, j, jstart, jend, img);
	draw(i, iend, j + 150, jstart + 150, jend + 50, img);
	i += 50;
	iend += 50;
	draw(i, iend, j, jstart, jend, img);
	draw(i, iend, j + 150, jstart + 150, jend + 50, img);


	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
