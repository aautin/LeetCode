/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:17:03 by aautin            #+#    #+#             */
/*   Updated: 2024/06/26 22:45:40 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int xor = 0; 
		for (int argI = 1; argI < argc; argI++)
		{
			xor = xor ^ atoi(argv[argI]);
			printf("[%s]: %d\n", argv[argI], xor);
		}
	}
	
	return (0);
}
