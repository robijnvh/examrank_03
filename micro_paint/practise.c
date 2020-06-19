/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practise.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 18:29:18 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/19 18:36:42 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "practise.h"

char	*get_data(FILE *file, t_data *data)
{
	char	*tmp;
	int		i;

	if (fscanf(file, "%d %d %c\n", &data->width, &data->heigth, &data->background) != 3)
		return (NULL);
	if ()
}

int		main(int argc, char **argv)
{
	t_data	data;
	FILE	*file;
	char	*res;

	data.width = 0;
	data.heigth = 0;
	data.background = 0;
	res = NULL;
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(file, "r")))
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
	if (file)
		fclose(file);
	if (res)
		free(res);
	return (0);
}