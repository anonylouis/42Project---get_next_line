/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:58:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/02 15:39:49 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "./srcs/get_next_line.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("./getNextLine text1.txt text2.txt text3.txt etc...\n");
		printf("Read simultaneously one line by one line text1.txt, text2.txt ... using the get_next_line function\n");
		return 0;
	}

	int		fd[argc - 1];
	char	*s[argc - 1];
	for(int i = 1; i < argc; ++i)
	{
		fd[i - 1] = open(argv[i], O_RDONLY);
		if (fd[i - 1] < 0)
		{
			printf("Can't open %s\n", argv[i]);
			return (1);
		}
	}
	int	finished = 0;

	while (!finished)
	{
		finished = 1;
		for(int i = 1; i < argc; ++i)
		{
			if (s[i - 1])
			{
				finished = 0;
				free(s[i - 1]);
				s[i - 1] = get_next_line(fd[i - 1]);
				printf("%s", s[i - 1]);
			}
		}
	}
    return (0);
}
