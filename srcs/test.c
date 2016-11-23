#include "libft.h"
#include "fillit.h"

void	printarray(const int *arr, int size)
{
	while (size--)
	{
		ft_putnbr((*arr++) + 1);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

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

void		printgrid(t_sol *solution)
{
	int		size;
	int		cnt;
	int		grid[GRID_SIZE][GRID_SIZE];

	size = tablen(solution->tiles);
	cnt = 0;
	while (cnt < GRID_SIZE)
		ft_memset(grid[cnt++], 0, sizeof(int) * GRID_SIZE);
	cnt = 0;
	while (cnt < size)
		place(grid, solution->tiles, solution->seq[cnt++]);
	cnt = 0;
	while (cnt < GRID_SIZE)
	{
		size = 0;
		while (size < GRID_SIZE)
		{
			ft_putchar('A' + grid[cnt][size++] - 1);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		cnt++;
	}
}

int			main()
{
	int		cnt;
	t_tile	**tiles;
	t_sol	*solution;

	tiles = get_tiles("test1.fillit");
	if (!tiles)
		return (1);
	cnt = 0;
	solution = get_solution(tiles);
	while (tiles[cnt])
	{
		print_tile(tiles[cnt], cnt);
		++cnt;
	}
	ft_putnbr(solution->minsize);
	ft_putchar('\n');
	printarray(solution->seq, 4);
	printgrid(solution);
	return 0;
}
