#include <stdio.h>
#include <string.h>

void convert(long long int x, int s, int t)
{

    long long int base10number = 0;

    long long int position = 1;
    while (x != 0)
    {
        int digit = x % 10;
        base10number += digit * position;
        position *= s;
        x /= 10;
    }

    char result[100];

    int index = 0;
    while (base10number != 0)
    {
        int digit = base10number % t;
        result[index] = digit + '0';
        base10number /= t;
        index++;
    }

    for(int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    puts("");
}

int main()
{
    long long int x;
    int t;
    int s;

    scanf("%lld %d %d", &x, &s, &t);

    convert(x, s, t);
}
