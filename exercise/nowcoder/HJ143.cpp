#include <stdio.h>
#include <stdint.h>

const int MOD = 1e9 + 7;

int64_t fast_power(int64_t a, int64_t b)
{
    int64_t ans = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    if(n <= 2)
    {
        printf("0\n");
        return 0;
    }

    int three_n = n / 3;
    int rem_n = n - three_n;
    int rp = (n >> 1) - three_n;
    int tp = three_n - rp;

    int64_t ans = 1;
    int64_t inv = 1;
    for(int i = 0; i < tp; i++)
    {
        ans *= (three_n - i);
        ans %= MOD;
        ans *= (three_n - i);
        ans %= MOD;
        inv *= (i + 1);
        inv %= MOD;
    }
    inv = fast_power(inv, MOD - 2);
    ans *= inv;
    ans %= MOD;
    for(int i = 0; i < rp; i++)
    {
        ans *= (rem_n - i);
        ans %= MOD;
    }
    for(int i = 1; i <= rem_n; i++)
    {
        ans *= i;
        ans %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}