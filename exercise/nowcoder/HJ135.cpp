#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <iostream>

const int MAX_N = 1e5 + 10;
// const int MAX_N = 110;

std::vector<int> mp[MAX_N];
uint64_t ans[MAX_N];
uint32_t num[MAX_N];
bool book[MAX_N];

void dfs(int ind, int parent)
{
    if(book[ind] == true)
    {
        num[ind]++;
        ans[ind]++;
    }
    for(int i = 0; i < mp[ind].size(); i++)
    {
        int v = mp[ind][i];
        if(v != parent)
        {
            dfs(v, ind);
            ans[ind] += (uint64_t)num[v] * num[ind] << 1;
            num[ind] += num[v];
        }
    }
}

int main()
{
    int n, k;
    int u, v;

    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    scanf("%d", &k);
    memset(book, false, sizeof(book));
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &u);
        book[u] = true;
    }

    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    dfs(1, 0);

    for(int i = 1; i < n; i++)
    {
        printf("%llu ", ans[i]);
    }
    printf("%llu\n", ans[n]);
    return 0;
}
