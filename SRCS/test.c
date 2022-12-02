void	test1(t_data *data, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	if (map->y < SIZE_Y && map->x < SIZE_X && map->x > -1 && map->y > -1)
  	  mlx_put_pixel(data, x, y, 0x00FF0000);
	while (map->x0 <= map->x1 && map->y0 <= map->y1)
	{
		if (p >= 0)
		{
			p = p + (2 * (dy - dx));
			map->y0++;
		}
    else
			p = p + (2 * dy);
    map->x0++;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	draw_line(t_data *data)
{
	int		dx;
	int		dy;

  dx = abs(x0 - x1);
  dy = abs(y0 - y1);
	if (map->x0 >= map->x1)
	{
		if (dx >= dy)
			test1(map, dx, dy);
		else if (dx < dy)
			test2(map, dx, dy);
	}
	else if (map->x0 < map->x1)
	{
		if (dx > dy)
			test3(map, dx, dy);
		else if (dx <= dy)
			test4(map, dx, dy);
	}
}
