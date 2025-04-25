#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAX_N = 1e4;

int main()
{
    int t;
    int count[30];
    char str[MAX_N];

    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%s", str);
        int len = strlen(str);
        memset(count, 0, sizeof(count));
        for(int i = 0; i < len; i++)
        {
            count[str[i] - 'a']++;
        }
        std::sort(count, count + 26);
        int ans = 0;
        for(int i = 25; i >= 0; i--)
        {
            if(count[i] <= 0)
            {
                break;
            }
            ans += count[i] * (i + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
