/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_paint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 11:29:01 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/19 17:57:35 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

/* str met aantal bg chars */
char	*get_data(FILE *file, t_data *data)
{
	int		i;
	char	*tmp;

	if (fscanf(file, "%d %d %c\n", &data->width, &data->height, &data->background) != 3)
		return (NULL);
	if (data->width <= 0 || data->width > 300 || data->height <= 0 || data->height > 300)
		return (NULL);
	tmp = (char*)malloc(sizeof(*tmp) * (data->width * data->height));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < data->width * data->height)
	{
		tmp[i] = data->background;
		i++;
	}
	return (tmp);
}

int		check_circle(float x, float y, t_data *data)
{
	float	dist;

	dist = sqrtf(powf(x - data->x, 2.0) + powf(y - data->y, 2.0));
	if (dist <= data->radius)
	{
		if ((data->radius - dist) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

int		make_shape(t_data *data, char *res)
{
	int	y;
	int	x;
	int	check;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			check = check_circle((float)x, (float)y, data);
			if ((data->type == 'c' && check == 2)
				|| (data->type == 'C' && check))
				res[(y * data->width) + x] = data->color;
			x++;
		}
		y++;
	}
	return (0);
}

int		make_shapes(FILE *file, t_data *data, char *res)
{
	int		ret;

	while ((ret = fscanf(file, "%c %f %f %f %c\n", &data->type, &data->x, &data->y, &data->radius, &data->color)) == 5)
	{
		if (data->radius <= 0.00000000 || (data->type != 'c' && data->type != 'C'))
			return (0);
		make_shape(data, res);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void	draw_shape(t_data *data, char *res)
{
	int	i;

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
	FILE	*file;
	t_data	data;
	char	*res;

	data.width = 0;
	data.height = 0;
	data.background = 0;
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
	if (!(make_shapes(file, &data, res)))
	{
		if (file)
			fclose(file);
		if (res)
			free(res);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	draw_shape(&data, res);
	if (file)
		fclose(file);
	if (res)
		free(res);
	return (0);
}
