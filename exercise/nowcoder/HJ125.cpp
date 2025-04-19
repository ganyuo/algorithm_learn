/* AC 573ms */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>

const int MAX_N = 5e5 + 10;
// const int MAX_N = 100;

uint64_t n, a, b;
uint32_t wight[MAX_N];
std::vector<int> mp[MAX_N];
bool visit[MAX_N];
uint64_t node_num;
bool (*check)(uint32_t);

bool gt_a_check(uint32_t wight)
{
    return a < wight;
}

bool le_b_check(uint32_t wight)
{
    return wight < b;
}

bool amid_ab_check(uint32_t wight)
{
    return a < wight && wight < b;
}

void dfs(int u)
{
    if(visit[u] == true)
    {
        return;
    }
    visit[u] = true;
    node_num++;
    for(int i = 0; i < mp[u].size(); i++)
    {
        dfs(mp[u][i]);
    }
}

uint64_t count_path()
{
    uint64_t count = 0;
    memset(visit, false, sizeof(visit));
    for(int i = 1; i <= n; i++)
    {
        if(check(wight[i]) == false)
        {
            visit[i] = true;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        node_num = 0;
        dfs(i);
        if (node_num >= 2)
        {
            count += node_num * (node_num - 1) / 2;
        }
    }
    return count;
}

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", wight + i);
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    uint64_t total_count = n * (n - 1) / 2;
    check = gt_a_check;
    uint64_t gt_a_count = count_path();
    check = le_b_check;
    uint64_t le_b_count = count_path();
    check = amid_ab_check;
    uint64_t amid_ab_count = count_path();

    uint64_t ans = total_count - gt_a_count - le_b_count + amid_ab_count;
    printf("%llu\n", ans);

    return 0;
}
