#include <stdio.h>
#include <string.h>
#include <set>

int main()
{
    int n, ans;
    int weight[15];
    int count[15];

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", weight + i);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", count + i);
    }

    std::set<int> s;
    s.insert(0);
    for(int i = 1; i <= n; i++)
    {
        std::set<int> temp(s);
        for(auto iter = temp.begin(); iter != temp.end(); iter++)
        {
            for(int j = 1; j <= count[i]; j++)
            {
                s.insert(*iter + j * weight[i]);
            }
        }
    }
    printf("%d\n", s.size());

    return 0;
}
