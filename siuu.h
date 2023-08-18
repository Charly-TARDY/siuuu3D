#ifndef SIUUU_H
#define SIUUU_H

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>

#include <mlx.h>

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

typedef struct s_flag
{
	int flag;
}	t_flag;

#endif
