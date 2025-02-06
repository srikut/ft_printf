#include<unistd.h>

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
	while(n > 15)
	{
		n 
	}
}
int	ft_print_hex(unsigned int n, const char *format)
{
	const char *nbr;
	size_t	index;

	nbr = (char *)malloc(sizeof(char) * 16);
	if(!nbr)
		return(0);
	if(*format == 'x')
		nbr = make_index_lower(nbr);
	else
		nbr = make_index_upper(nbr);


}