#include <stdio.h>
#include <string.h>

const int MAX_N = 100 + 10;

struct node_t
{
    int x, y;
    int pre;
};

bool mp[MAX_N][MAX_N];
node_t que[MAX_N * MAX_N];

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    memset(mp, false, sizeof(mp));
    for(int i = 0; i < n; i++)
    {
        int val;
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &val);
            if(val == 0)
            {
                mp[i][j] = true;
            }
        }
    }
    // if(n == 1 && m == 1)
    // {
    //     printf("(0, 0)\n");
    //     return 0;
    // }

    int front = 0, back = 1;
    que[0].x = n - 1;
    que[0].y = m - 1;
    que[0].pre = -1;
    mp[n - 1][m - 1] = false;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(front < back)
    {
        bool found = false;
        for(int i = 0; i < 4; i++)
        {
            node_t temp;
            temp.x = que[front].x + dir[i][0];
            temp.y = que[front].y + dir[i][1];
            if (0 <= temp.x && temp.x < n &&
                0 <= temp.y && temp.y < m &&
                mp[temp.x][temp.y] == true)
            {
                temp.pre = front;
                mp[temp.x][temp.y] = false;
                que[back] = temp;
                back++;
                if(temp.x == 0 && temp.y == 0)
                {
                    found = true;
                    break;
                }
            }
        }
        if(found == true)
        {
            break;
        }
        front++;
    }
    // if(front >= back)
    // {
    //     printf("no found\n");
    //     return 0;
    // }

    int pre = back - 1;
    while(pre != -1)
    {
        printf("(%d,%d)\n", que[pre].x, que[pre].y);
        pre = que[pre].pre;
    }
    return 0;
}