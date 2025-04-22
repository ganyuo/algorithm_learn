#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 1e5 + 10;
const int MOD = 1e9 + 7;

char str[MAX_N];
uint64_t num[MAX_N];

int main()
{
    int n;
    uint64_t ans;

    scanf("%d", &n);
    scanf("%s", str);

    ans = 0;
    for(int i = 2; i <= n; i++)
    {
        num[i] = n - i + 1;
        num[i] *= (num[i] + 1);
        num[i] >>= 1;
    }
    for(int i = 1; i < n; i++)
    {
        if(str[i] == '0')
        {
            continue;
        }
        for(int j = 0; j < i; j++)
        {
            if(str[j] == '0')
            {
                ans += num[i - j + 1];
            }
        }
        ans %= MOD;
    }
    printf("%llu", ans);
    return 0;
}