#include "ft_printf.h"

static char	*make_index_lower(char *index)
{
	index[0] = '0';
	index[1] = '1';
	index[2] = '2';
	index[3] = '3';
	index[4] = '4';
	index[5] = '5';
	index[6] = '6';
	index[7] = '7';
	index[8] = '8';
	index[9] = '9';
	index[10] = 'a';
	index[11] = 'b';
	index[12] = 'c';
	index[13] = 'd';
	index[14] = 'e';
	index[15] = 'f';
	index[16] = '\0';
	return(index);
}
static char	*make_index_upper(char *index)
{
	index[0] = '0';
	index[1] = '1';
	index[2] = '2';
	index[3] = '3';
	index[4] = '4';
	index[5] = '5';
	index[6] = '6';
	index[7] = '7';
	index[8] = '8';
	index[9] = '9';
	index[10] = 'A';
	index[11] = 'B';
	index[12] = 'C';
	index[13] = 'D';
	index[14] = 'E';
	index[15] = 'F';
	index[16] = '\0';
	return(index);
}
int	put_hex(int n, const char *nbr)
{
	int		count;
	int	ret;
	size_t	index;

	count = 0;
	index = n % 16;
	if (n >= 16)
	{
		ret = put_hex(n / 16, nbr);
		if (ret > 0)
			count += ret;
	}
	ret = write(1, &nbr[index], 1);
	if (ret > 0)
			count += ret;
	return (count);
}
int	ft_print_hex(unsigned int n, const char format)
{
	char *nbr;
	int	count;

	nbr = (char *)malloc(sizeof(char) * 16);
	if(!nbr)
		return(0);
	if(format == 'x')
		nbr = make_index_lower(nbr);
	else
		nbr = make_index_upper(nbr);
	count = 0;
	count += put_hex(n, nbr);
	free(nbr);
	return (count);
}


// #include <unistd.h> // write()のため
// #include <stdlib.h> // malloc()のため
// #include <stdio.h>  // printf()などのため

// // ここに先ほどの関数群を貼り付けてもOKですが、
// // すでに別ファイルで定義している場合はヘッダーを作ってincludeするのが望ましいです。
// // ひとまずテスト用としてプロトタイプ宣言だけ入れておきます。

// int ft_print_hex(unsigned int n, const char *format);

// int main(void)
// {
//     int count;

//     // いくつかの値でテストしてみましょう
//     // 'x' (小文字) と 'X' (大文字) 両方を試してみます

//     count = ft_print_hex(0, "x");
//     printf(" => 出力文字数: %d\n", count);

//     count = ft_print_hex(42, "x"); // 42 -> 2a
//     printf(" => 出力文字数: %d\n", count);

//     count = ft_print_hex(255, "x"); // 255 -> ff
//     printf(" => 出力文字数: %d\n", count);

//     // 大文字バージョン(X)
//     count = ft_print_hex(255, "X"); // 255 -> FF
//     printf(" => 出力文字数: %d\n", count);

//     count = ft_print_hex(4096, "X"); // 4096 -> 1000
//     printf(" => 出力文字数: %d\n", count);

//     return 0;
// }
