/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practise.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 18:29:45 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/22 11:57:17 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRACTISE_H
# define PRACTISE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_data
{
	int			width;
	int			height;
	char		background;
	char		type;
	char		fill;
	float		x;
	float		y;
	float		w;
	float		h;
}				t_data;

#endif
