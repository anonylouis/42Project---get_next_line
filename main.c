/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:58:26 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/02 18:34:15 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./srcs/get_next_line.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("./getNextLine text1.txt text2.txt text3.txt etc...\n");
		printf("Read text1.txt line by line, text2.txt line by line etc.. using the get_next_line function.\n");
		return 0;
	}

	for(int i = 1; i < argc; ++i)
	{
		int fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			printf("Can't open %s\n", argv[i]);
		else
		{
			printf("Reading %s :\n\n", argv[i]);
			char	*s;
			while ((s = get_next_line(fd)) != NULL)
			{
				printf("%s", s);
				free(s);
			}
			close(fd);
		}
		if (i != argc -1)
			printf("\n");
	}
    return (0);
}
