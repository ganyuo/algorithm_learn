#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 100 + 10;
const int MAX_M = 6e4 + 10;

int n, ans;
int num[MAX_N];
bool prime[MAX_M];
bool visit[MAX_N];
int match[MAX_N];
bool map[MAX_N][MAX_N];

void init_prime()
{
    memset(prime, true, MAX_M);
    prime[0] = false;
    prime[1] = false;
    for(uint64_t i = 2; i < MAX_M; i++)
    {
        if(prime[i] == true)
        {
            for(uint64_t j = i * i; j < MAX_M; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

bool dfs(int s)
{
    for(int i = 0; i < n; i++)
    {
        if(visit[i] == false && map[s][i] == true)
        {
            visit[i] = true;
            if(match[i] < 0 || dfs(match[i]))
            {
                match[s] = i;
                match[i] = s;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    init_prime();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    memset(map, false, sizeof(map));
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(prime[num[i] + num[j]] == true)
            {
                map[i][j] = true;
                map[j][i] = true;
            }
        }
    }

    ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < n; i++)
    {
        memset(visit, false, sizeof(visit));
        if((num[i] & 1) && dfs(i) == true)
        {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}