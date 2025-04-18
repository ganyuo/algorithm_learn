/* 答案错误 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <algorithm>

const int MAX_N = 1e6 + 10;

struct node_t
{
    int64_t len;
    int64_t num;
};

node_t edge[MAX_N];

bool cmp(const node_t &a, const node_t &b)
{
    return a.len > b.len;
}

int main()
{
    int t, n;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &edge[i].len, &edge[i].num);
        }

        std::sort(edge, edge + n, cmp);
        for(int i = 1, j = 0; i < n; i++)
        {
            if(edge[i].len == edge[j].len)
            {
                if(edge[j].num < 3)
                {
                    edge[j].num += edge[i].num;
                }
            }
            else
            {
                j++;
                edge[j].len = edge[i].len;
                edge[j].num = edge[i].num;
            }
        }

        int64_t max_len = 0;
        int max_ind = -1;
        for(int i = 0; i < n; i++)
        {
            if(edge[i].num >= 2)
            {
                max_ind = i;
                max_len = edge[i].len;
                break;
            }
        }
        if(max_ind == -1)
        {
            printf("-1\n");
            continue;
        }

        double ans = -1;
        edge[max_ind].num -= 2;
        for(int i = 0; i < n; i++)
        {
            if(edge[i].len > (max_len << 1) || edge[i].num <= 0)
            {
                continue;
            }
            double bottom = edge[i].len;
            double height = max_len;
            bottom /= 2;
            height = sqrt(height * height - bottom * bottom);
            double area = bottom * height;
            if(ans < area)
            {
                ans = area;
            }
        }
        printf("%.10lf\n", ans);
    }

    return 0;
}
