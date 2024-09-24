/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:55:26 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/22 22:29:36 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn
 * src が指す文字列を末尾のヌルバイト ('\0') も含めて dest が指すバッファにコピーす
 * る。つの文字列は重なってはならない。受け側の文字列 dest は コピーを受け取るのに十分な大き
 * さでなければならない。 バッファオーバーランに気を付けること!
 * @param dest 受け側の文字列destへのポインタ
 * @param str ヌル終端文字列
 * @return 受け側の文字列destへのポインタを返す。
 * @sa https://ja.manpages.org/strcpy/3
 */

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}
