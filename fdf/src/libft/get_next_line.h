/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:54:48 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/05 12:15:01 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"
# include <unistd.h>

# define BUFF_SIZE 10000
# define FD_NB 4864

int		get_next_line(const int fd, char **line);

#endif
