#include <unistd.h>

void pr_num(int a)
{
    char str[10] = "0123456789";

    if (a > 9)
        pr_num(a / 10);
    write(1, &str[a % 10], 1);
}

int main()
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i % 3 == 0 && i % 5 == 0)
            write (1, "fizzbuzz", 8);
        else
            pr_num(i);
        i++;
        write (1, "\n", 1); 
    }
}