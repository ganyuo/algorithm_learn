#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

const int MAX_N = 10e3 + 10;
// const int MAX_N = 110;

struct pair_t
{
    int u, v, w;
};

int main()
{
    int n, c, m;
    int cost[MAX_N];
    int pow[MAX_N];
    int64_t dp[5][MAX_N];
    bool spe[MAX_N];
    pair_t pair[MAX_N];

    scanf("%d %d %d", &n, &c, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%u %u", &cost[i], &pow[i]);
    }
    memset(spe, false, sizeof(spe));
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %u", &pair[i].u, &pair[i].v, &pair[i].w);
        pair[i].u--;
        pair[i].v--;
        spe[pair[i].u] = true;
        spe[pair[i].v] = true;
    }

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        if(spe[i] == true)
        {
            continue;
        }
        for(int p = 4; p > 0; p--)
        {
            for(int j = c; j >= cost[i]; j--)
            {
                dp[p][j] = max(dp[p][j], dp[p - 1][j - cost[i]] + pow[i]);
            }
        }
    }
    for(int i = 0; i < m; i++)
    {

        for(int p = 4; p > 0; p--)
        {
            for(int j = c; j > 0; j--)
            {
                if (j - cost[pair[i].u] >= 0)
                {
                    dp[p][j] = max(dp[p][j], dp[p - 1][j - cost[pair[i].u]] + pow[pair[i].u]);
                }
                if (j - cost[pair[i].v] >= 0)
                {
                    dp[p][j] = max(dp[p][j], dp[p - 1][j - cost[pair[i].v]] + pow[pair[i].v]);
                }
                if (j - cost[pair[i].u] - cost[pair[i].v] >= 0 && p >= 2)
                {
                    dp[p][j] = max(dp[p][j], dp[p - 2][j - cost[pair[i].u] - cost[pair[i].v]]
                        + pow[pair[i].u] + pow[pair[i].v] + pair[i].w);
                }
            }
        }
    }
    uint64_t ans = 0;
    for(int i = 0; i < 5; i++)
    {
        ans = max(ans, dp[i][c]);
    }
    printf("%llu\n", ans);

    return 0;
}