#include "libft.h"
#include "fillit.h"

void	print_tile(t_tile *tile)
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
		shape[p->y][p->x] = '#';
	}
	count = 0;
	while (count < 4)
	{
		write(1, shape[count++], 4);
		ft_putchar('\n');
	}
}

int main()
{
	t_tile	**tiles;
	tiles = get_tiles("test.txt");
	if (!tiles)
		return (1);
	while (*tiles)
	{
		print_tile(*tiles++);
	}
	return 0;
}
