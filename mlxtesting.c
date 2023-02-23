#include "siuu.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int color_choose(int flag)
{
	int color;
	if (flag == 1)
		return color = create_trgb(0, 255, 0, 0);
	if (flag == 2)
		return color = create_trgb(0, 255, 127, 0);
	if (flag == 3)
		return color = create_trgb(0, 255, 255, 0);
	if (flag == 4)
		return color = create_trgb(0, 0, 255, 0);
	if (flag == 5)
		return color = create_trgb(0, 0, 0, 255);
	if (flag == 6)
		return color = create_trgb(0, 75, 0, 130);
	if (flag == 7)
		return color = create_trgb(0, 148, 0, 211);
	return 0;
}

void draw(int i, int iend, int j, int jstart, int jend, t_data img, int color)
{
	while (i < iend)
	{
		while (jstart < jend)
			my_mlx_pixel_put(&img, i, jstart++, color);
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

int print_siuu(t_data img)
{
	int i = 50;
	int iend = 150;
	int j = 50;
	int jstart = j;
	int jend = 75;
	int	color = 0;
	if (img.flag < 8)
		color = color_choose(img.flag++);
	else if (img.flag == 8)
		img.flag = 1;
	// S
	printf("couleur atm %d\n", img.flag);
	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend - 75, j + 25, jstart + 25, jend + 50, img, color);
	draw(i, iend, j + 75, jstart, jend + 75, img, color);
	draw(i + 75, iend, j + 100, jstart + 100, jend + 150, img, color);
	draw(i, iend, j + 150, jstart + 150, jend + 150, img, color);
	// I
	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);
	draw(175, 200, 50, 50, 225, img, color);
	// U
	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);
	i = 225;
	iend = 250;
	jend = 225;

	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img, color);
	draw(i + 75, iend + 75, j, jstart, jend, img, color);

	i = 350;
	iend = 375;
	jend = 225;

	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);

	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img, color);
	draw(i + 75, iend + 75, j, jstart, jend, img, color);

	i = 475;
	iend = 500;
	jend = 225;

	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);

	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img, color);
	draw(i + 75, iend + 75, j, jstart, jend, img, color);

	i = 600;
	iend = 625;
	jend = 225;

	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);

	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend + 75, j + 150, jstart + 150, jend, img, color);
	draw(i + 75, iend + 75, j, jstart, jend, img, color);

	// !

	i = 750;
	iend = 775;
	jend = 175;

	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);

	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend, j + 150, jstart + 150, jend + 50, img, color);
	i += 50;
	iend += 50;

	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);

	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend, j + 150, jstart + 150, jend + 50, img, color);
	i += 50;
	iend += 50;

	if (img.flag == 8)
	{
		img.flag = 1;
		color = color_choose(img.flag++);
	}
	else if (img.flag < 8)
		color = color_choose(img.flag++);
	draw(i, iend, j, jstart, jend, img, color);
	draw(i, iend, j + 150, jstart + 150, jend + 50, img, color);
	return 0;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 720, "Siuu");
	img.flag = 1;
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_siuu(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, (1L << 0), print_siuu, &img);
	mlx_loop(mlx);
}
