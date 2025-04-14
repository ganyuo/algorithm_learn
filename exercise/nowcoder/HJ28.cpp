#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAXN = 100 + 10;
const int MAXM = 60000 + 10;

struct edge_t
{
    int s, d;
};


int n, ans;
int num[MAXN];
bool visit[MAXN];
bool prime[MAXM];
int en;
edge_t edge[MAXN * MAXN];
// bool map[MAXN][MAXN];

void init_prime()
{
    memset(prime, true, MAXM);
    prime[0] = false;
    prime[1] = false;
    for(uint64_t i = 2; i < MAXM; i++)
    {
        if(prime[i] == true)
        {
            for(uint64_t j = i * i; j < MAXM; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void dfs(int inds, int pn)
{
    if(pn > ans)
    {
        ans = pn;
    }
    for(int i = inds; i < en; i++)
    {
        if(visit[edge[i].s] == true || visit[edge[i].d] == true)
        {
            continue;
        }
        visit[edge[i].s] = true;
        visit[edge[i].d] = true;
        dfs(i + 1, pn + 1);
        visit[edge[i].s] = false;
        visit[edge[i].d] = false;
    }
}

int main()
{
    init_prime();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    // memset(map, false, sizeof(map));
    en = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(prime[num[i] + num[j]] == true)
            {
                edge[en].s = i;
                edge[en].d = j;
                en++;
                // map[i][j] = true;
                // map[j][i] = true;
            }
        }
    }
    // printf("00: ");
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%-3d", i);
    // }
    // printf("\n");
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%-2d: ", i);
    //     for(int j = 0; j < n; j++)
    //     {
    //         if(map[i][j] == true)
    //         {
    //             printf("1  ");
    //         }
    //         else
    //         {
    //             printf("0  ");
    //         }
    //     }
    //     printf("\n");
    // }

    ans = 0;
    memset(visit, false, sizeof(visit));
    dfs(0, 0);

    printf("%d\n", ans);

    return 0;
}