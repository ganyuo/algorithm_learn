#include <stdio.h>
#include <stdint.h>
#include <string.h>

const int MAX_N = 100000 + 10;
const uint64_t MOD = 10e9 + 7;

uint64_t num[MAX_N];

int main()
{
    int n, k;
    uint64_t m;
    uint64_t ans = 0;

    scanf("%d %llu %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        ans += 2 * num[i];
        ans += (num[i] & m);
        ans %= MOD;
    }



    printf("%d\n", ans);
    return 0;
}