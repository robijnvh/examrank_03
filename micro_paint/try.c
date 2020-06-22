/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 12:24:37 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/22 12:55:01 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "try.h"

char	*get_data(FILE *file, t_data *data)
{
	int		i;
	char	*tmp;

	if (fscanf(file, "%d %d %c\n", &data->width, &data->height, &data->back) != 3)
		return (NULL);
	if (data->width <= 0 || data->width > 300 || data->height <= 0 || data->height > 300)
		return (NULL);
	tmp = (char*)malloc(sizeof(*tmp) * (data->width * data->height));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < data->width * data->height)
	{
		tmp[i] = data->back;
		i++;
	}
	return (tmp);
}

int		check_square(float x, float y, t_data *data)
{
	if ((x < data->x) || ((data->x + data->w) < x) || (y < data->y) || ((data->y + data->h) < y))
		return (0);
	if ((x - data->x < 1.00000000) || ((data->x + data->w) - x < 1.000000) || (y - data->y < 1.00000000) || ((data->y + data->h) - y < 1.000000))
		return (2);
	return (1);
}

int		make_shape(t_data *data, char *res)
{
	int	x;
	int	y;
	int	check;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			check = check_square((float)x, (float)y, data);
			if ((data->type == 'r' && check == 2) || (data->type == 'R' && check))
				res[(y * data->width) + x] = data->fill;
			x++;
		}
		y++;
	}
	return (0);
}

int		make_shapes(FILE *file, t_data *data, char *res)
{
	int ret;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &data->type, &data->x, &data->y, &data->w, &data->h, &data->fill)) == 6)
	{
		if (data->w < 0.00000000 || data->h < 0.00000000 || (data->type != 'r' && data->type != 'R'))
			return (0);
		make_shape(data, res);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void	draw_it(t_data *data, char *res)
{
	int i;

	i = 0;
	while (i < data->height)
	{
		write(1, res + (i * data->width), data->width);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_data	data;
	FILE	*file;
	char	*res;

	data.width = 0;
	data.height = 0;
	data.back = 0;
	res = NULL;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (!(res = get_data(file, &data)))
	{
		if (file)
			fclose(file);
		if (res)
			free(res);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (!make_shapes(file, &data, res))
	{
		if (file)
			fclose(file);
		if (res)
			free(res);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	draw_it(&data, res);
	if (file)
		fclose(file);
	if (res)
		free(res);
	return (0);
}
