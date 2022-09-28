#include "minitalk.h"
/*
static void	ft_convert(char *s)
{
	int	pow;
	char	c;
	size_t	i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	write(1, &c, 1);
}
char *append_bit(char *str, char c)
{	
	size_t	i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char)*(ft_strlen(str) + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}
static void	checked_str2(int signo) 
{
	static char	*bits;
	static int	cnt_bit;

	cnt_bit++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		cnt_bit = 1;
	}
	if (signo == SIGUSR1)
		bits = append_bit(bits, '0');
	else
		bits = append_bit(bits, '1');
	if (cnt_bit == 8)
	{

		//ft_printf("test\n");
		ft_printf("append bits : %s\n",bits);
		//ft_convert(bits);
		free(bits);
		bits = NULL;
	}
}
*/
void checked_str(int signal)
{
	static int bit;
	static int i;
	
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%d\n",i);
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}
int main()
{
	ft_printf("Server PID : %d\n",getpid());
	while (1)
	{
		signal(SIGUSR1, checked_str);
		signal(SIGUSR2, checked_str);
		pause();
	}
	return (0);
}
