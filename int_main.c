/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:28:02 by brivera           #+#    #+#             */
/*   Updated: 2024/10/31 14:07:55 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv) 
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) 
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    while (1) 
    {
        line = get_next_line(fd);
        if (line == NULL) 
        {
            printf("----> fin de lectura \n");
            break;
        }
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}

