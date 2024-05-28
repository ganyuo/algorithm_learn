#include <stdio.h>
#include <string.h>

const int MAXN = 20;

struct node_t
{
    int x, y;
};

int n, k, ans;
char mp[MAXN][MAXN];
int node_num;
node_t nodes[MAXN * MAXN];
char row_v[MAXN], col_v[MAXN];

void dfs(int start, int count)
{
    if(count == k)
    {
        ans++;
        return;
    }
    for(int i = start; i < node_num; i++)
    {
        if(row_v[nodes[i].x] == 0 && col_v[nodes[i].y] == 0)
        {
            row_v[nodes[i].x] = 1;
            col_v[nodes[i].y] = 1;
            dfs(i + 1, count +  1);
            row_v[nodes[i].x] = 0;
            col_v[nodes[i].y] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    while(scanf("%d %d", &n, &k) != EOF)
    {
        if(n < 0 || k < 0)
        {
            break;
        }
        node_num = 0;
        // memset(mp, 0, sizeof(mp));
        for(int i = 0; i < n; i++)
        {
            scanf("%s", mp[i]);
            for(int j = 0; j < n; j++)
            {
                if(mp[i][j] == '#')
                {
                    nodes[node_num].x = i;
                    nodes[node_num].y = j;
                    node_num++;
                }
            }
        }
        if(k > node_num || k > n)
        {
            printf("0\n");
            continue;
        }

        ans = 0;
        memset(row_v, 0, sizeof(row_v));
        memset(col_v, 0, sizeof(col_v));
        dfs(0, 0);
        printf("%d\n", ans);
    }

    return 0;
}

/*
Sample Input
2 1
#.
.#
4 4
...#
..#.
.#..
#...
4 2
...#
..#.
.#..
#...
4 4
.#.#
..#.
.#..
#...
4 5
.#.#
..#.
.#..
#...
-1 -1

Sample Output
2
1
6
1
0

*/