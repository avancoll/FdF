/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:32 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/22 15:17:39 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	float	X = 0;
	float	Y = 0;

	float	A = 0;
	float	B = -35.264 * (M_PI / 180);
	float	C = -45 * (M_PI / 180);
	int	offset_x = 500;
	int	offset_y = 500;
	if (argc == 3)
	{
	int		ax = atoi(argv[1]);
	int		ay = atoi(argv[2]);
	printf("ax = %d\nay = %d\n", ax, ay);

	X = ax * (cos(B) * cos(C)) + ay * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C))) + 0 * ((cos(A) * sin(B) * cos(C)) + (sin(A) * sin(C))) + offset_x;
	Y = ax * (cos(B) * sin(C)) + ay * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B))) + 0 * ((cos(A) * sin(B) * sin(C)) - (sin(A) * cos(C))) + offset_y;
	printf("X = %f\nY = %f\n", X, Y);
	}
}
