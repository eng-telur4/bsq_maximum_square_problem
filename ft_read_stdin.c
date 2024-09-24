/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:20:20 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 04:28:17 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 標準入力から文字列を読み込む関数
 * @return 読み込んだ文字列
 */
char	*read_stdin(void)
{
	char	buf[8192];

	read(STDIN_FILENO, buf, sizeof(buf));
	return (ft_substr(buf, 0, ft_strlen(buf) - 1));
}
