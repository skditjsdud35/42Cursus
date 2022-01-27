#include <unistd.h>

void ft_ultimate_div_mod(int *a, int *b)
{
        int a_tmp;
        int b_tmp;

        a_tmp = *a;
        b_tmp = *b;

        *a = a_tmp / b_tmp;
        *b = a_tmp % b_tmp;
}
