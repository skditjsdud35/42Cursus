#include "minitalk.h"

void char_to_bits(int pid, char c)
{
	int bit;

	bit  = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0) 
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}
			
int main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			char_to_bits(pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("Error : wrong format\n");
	return (0);
}
