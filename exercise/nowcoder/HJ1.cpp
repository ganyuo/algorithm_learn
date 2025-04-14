#include <stdio.h>
#include <string.h>

int main()
{
    char str[100 + 10];
    while(scanf("%s", str) != EOF)
    {
        continue;
    }
    printf("%d\n", strlen(str));
    return 0;
}