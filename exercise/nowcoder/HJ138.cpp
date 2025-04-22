#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>

const int MAX_N = 2e5 + 10;
// const int MAX_N = 20;
const int MOD = 1e9 + 7;

int n, k;
int8_t book[MAX_N];
std::vector<int> mp[MAX_N];

int64_t limb;

void dfs(int ind)
{
    book[ind] = 2;
    for(int i = 0; i < mp[ind].size(); i++)
    {
        if(book[mp[ind][i]] == 1)
        {
            dfs(mp[ind][i]);
        }
        else if(book[mp[ind][i]] == 0)
        {
            limb++;
        }
    }
}

int main()
{
    int cost;
    int64_t num;

    scanf("%d %d", &n, &k);
    memset(book, 0, sizeof(book));
    for(int i = 0; i < k; i++)
    {
        int bn;
        scanf("%d", &bn);
        book[bn] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    cost = 0;
    num = 1;
    for(int i = 1; i <= n; i++)
    {
        if(book[i] == 1)
        {
            limb = 0;
            dfs(i);
            cost++;
            num *= limb;
            num %= MOD;
        }
    }

    printf("%d %lld\n", cost, num);
    return 0;
}