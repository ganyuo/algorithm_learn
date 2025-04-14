#include <stdio.h>
#include <string.h>

int main()
{
    int num[500 + 10];
    int n, a;

    memset(num, 0, sizeof(num));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if(0 <= a && a <= 500)
        {
            num[a] = 1;
        }
    }

    for(int i = 0; i <= 500; i++)
    {
        if(num[i] != 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}