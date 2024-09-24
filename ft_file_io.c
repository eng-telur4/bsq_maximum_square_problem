/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:42:05 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 03:28:27 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 第一引数で渡されたファイル名のファイルを開いて文字列として返す関数
 * @param file_name 読み込みむファイルの名前
 * @return 読み込んだファイルの中身
 * @attention メモリ確保(malloc)できなかった場合はNULLが返る
 */
char	*read_file(char *file_name)
{
	char	c;
	int		fd;
	char	*ret_val;
	int		i;

	ret_val = (char *)malloc(get_file_size(file_name) * sizeof(char));
	if (ret_val == NULL)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (read(fd, &c, sizeof(char)) > 0)
		ret_val[i++] = c;
	return (ret_val);
}

/**
 * @fn
 * ファイルサイズを取得する
 * @param file_name 読み込みむファイルの名前
 * @return ファイルサイズ(バイト)
 */
int	get_file_size(char *file_name)
{
	int	fd;
	int	c;
	int	n;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	n = 0;
	while (read(fd, &c, sizeof(char)) > 0)
		n++;
	return (n);
}

/**
 * @fn
 * ファイルを行ごとに読み込む関数
 * @param buf ファイルバッファ
 * @return ファイルバッファbufを改行ごとに区切った文字列の配列
 * @attention ft_splitでNULLが返ってきた場合、そのままNULLが返る
 */
char	**read_lines(char *buf)
{
	return (ft_split(buf, "\n"));
}

/**
 * @fn
 * ファイルの行数を数える関数(buf版)
 * @param buf ファイルバッファ
 * @return ファイルバッファbufを改行ごとに区切ったときの文字列の総数
 */
int	get_line_count(char *buf)
{
	return (ft_strs_count(buf, "\n"));
}

/**
 * @fn
 * ファイルの行数を数える関数(lines版)
 * @param buf ファイルバッファ
 * @return ファイルバッファbufを改行ごとに区切ったときの文字列の総数
 */
int	get_line_countl(char **lines)
{
	int	count;

	count = 0;
	while (lines[count] != NULL)
		count++;
	return (count);
}
