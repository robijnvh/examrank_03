/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practise.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 17:40:28 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/19 17:46:19 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRACTISE_H
# define PRACTISE_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_data
{
	int			width;
	int			height;
	char		background;
	float		x;
	float		y;
	char		type;
	float		radius;
	char		fill;
}				t_data;

#endif
