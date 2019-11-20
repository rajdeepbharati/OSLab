#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter 3 integers (space separated): ");
    scanf("%d %d %d", &a, &b, &c);
    int min = (a < b ? (a < c ? a : c) : (b < c ? b : c));
    int max = (a > b ? (a > c ? a : c) : (b > c ? b : c));
    printf("Minimum of %d, %d, and %d is %d\n", a, b, c, min);
    printf("Maximum of %d, %d, and %d is %d\n", a, b, c, max);

    return 0;
}
