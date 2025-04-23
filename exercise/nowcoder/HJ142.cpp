#include <stdio.h>
#include <string.h>

const int MAX_N = 1e6 + 10;

int main()
{
    int count, len;
    char str[MAX_N];
    int mp[10] = {-1, 2, 3, 5, 5, 7, 7, 11, 11, 11};

    scanf("%d", &count);
    while (count--)
    {
        scanf("%s", str);
        len = strlen(str);
        printf("%d", mp[str[0] - '0']);
        for(int i = 1; i < len; i++)
        {
            printf("0");
        }
        printf("\n");
    }

    return 0;
}