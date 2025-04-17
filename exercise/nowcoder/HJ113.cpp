#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define min(a,b) (a<b)?a:b

const int MAX_N = 1e5 + 10;
const uint64_t MOD = 1e9 + 7;
const int MAX_LOOP = 32;

uint64_t fast_power(uint64_t a, uint64_t b)
{
    uint64_t ans = 1;
    while (b > 0)
    {
        if (b & 1)
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

uint64_t extern_gcd(uint64_t a, uint64_t b, int64_t &x, int64_t &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    uint64_t gcd = extern_gcd(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
}

uint64_t conbine(uint64_t n, uint64_t m)
{
    uint64_t ans = 1, inv = 1;

    for(int i = n; i > n - m; i--)
    {
        ans *= i;
        ans %= MOD;
    }
    for(int i = 1; i <= m; i++)
    {
        inv *= i;
        inv %= MOD;
    }
    inv = fast_power(inv, MOD - 2);
    return (ans * inv) % MOD;
}

uint64_t num[MAX_N];

int main()
{
    uint64_t n, m, k;
    uint64_t ans = 0;
    uint64_t prob[MAX_LOOP + 10];

    scanf("%llu %llu %llu", &n, &m, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    uint64_t div = fast_power(2, k);
    uint64_t div_inv = fast_power(div, MOD - 2);

    int loop = min(k, MAX_LOOP);
    uint64_t conb_sum = 0;
    for (int i = 0; i <= loop; i++)
    {
        uint64_t conb = conbine(k, i);
        conb_sum += conb;
        prob[i] = (conb * div_inv) % MOD;
    }
    if (k > MAX_LOOP)
    {
        conb_sum %= MOD;
        prob[MAX_LOOP + 1] = ((div + MOD - conb_sum) * div_inv) % MOD;
        loop++;
    }

    ans = 0;
    for (int i = 0; i < n; i++)
    {
        uint64_t exp = 0;
        for(int j = 0; j <= loop; j++)
        {
            exp = (exp + prob[j] * num[i]) % MOD;
            num[i] = (num[i] + (num[i] & m)) % MOD;
        }
        ans = (ans + exp) % MOD;
    }

    printf("%llu\n", ans);
    return 0;
}