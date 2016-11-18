#include "libft.h"
#include "fillit.h"

static void	print_tile(t_tile *tile, int index)
{
	int				count;
	char			shape[4][4];
	const t_point	*p;

	count = 0;
	while (count < 4)
		ft_memset(shape[count++], ' ', 4);
	count = 0;
	while (count < 4)
	{
		p = &(tile->dots[count++]);
		shape[p->y][p->x] = 'A' + index;
	}
	count = 0;
	while (count < 4)
	{
		write(1, shape[count++], 4);
		ft_putchar('\n');
	}
}

int			main()
{
	int		cnt;
	t_tile	**tiles;

	tiles = get_tiles("test.txt");
	if (!tiles)
		return (1);
	cnt = 0;
	while (tiles[cnt])
	{
		print_tile(tiles[cnt], cnt);
		++cnt;
	}
	return 0;
}
