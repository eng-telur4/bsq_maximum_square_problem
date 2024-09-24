/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:20:20 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 04:22:52 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*read_stdin(void)
{
	char	buf[8192];

	read(STDIN_FILENO, buf, sizeof(buf));
	return (ft_substr(buf, 0, ft_strlen(buf) - 1));
}
