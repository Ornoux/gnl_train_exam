/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:51:45 by npatron           #+#    #+#             */
/*   Updated: 2024/03/01 11:51:48 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#    define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

static char docu[INT_MAX];
int            k;

char    *get_next_line(int fd)
{
    char    buf[BUFFER_SIZE + 1];
    char    *line;
    int        i;
    int        j = 0;
    int        ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    ret = read(fd, buf, BUFFER_SIZE);
    while (ret)
    {
        i = 0;
        while (i < ret)
        {
            docu[j] = buf[i];
            i++;
            j++;
        }
        ret = read(fd, buf, BUFFER_SIZE);
    }
    i = k;
    while (docu[i] != '\n' && docu[i])
        i++;
    if (!docu[k])
        return (NULL);
    line = malloc(i - k + 2);
    i = 0;
    while (docu[k] != '\n' && docu[k])
    {
        line[i] = docu[k];
        i++;
        k++;
    }
    if (docu[k] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    else
    {
        line[i] = '\0';
        i++;
    }
    if (docu[k])
        k++;
    line[i] = '\0';
    return (line);
}
