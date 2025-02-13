#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
** ft_printf
**   書式文字列と可変長引数を受け取り、変換した結果を標準出力に出力する関数。
**   対応する変換: %c, %s, %p, %d, %i, %u, %x, %X, %%
*/
int	ft_printf(const char *format, ...);

/*
** 変換ごとの出力関数
*/
int	ft_print_char(int n);
int	ft_print_str(const char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, const char format);
int	ft_print_ptr(void *ptr);

#endif