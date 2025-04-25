#include <stdio.h>
#include <string.h>

const int MAX_N = 1e3 + 10;

int main()
{
    char str[MAX_N];
    int mp[256];

    scanf("%s", str);
    int len = strlen(str);
    memset(mp, 0, sizeof(mp));
    for(int i = 0; i < len; i++)
    {
        mp[str[i]]++;
    }
    for(int i = 0; i < len; i++)
    {
        if(mp[str[i]] == 1)
        {
            printf("%c\n", str[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}