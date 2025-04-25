#include <stdio.h>
#include <string.h>
#include <list>

int main()
{
    int n, val, b;
    std::list<int> lt;

    scanf("%d", &n);
    scanf("%d", &val);
    lt.push_back(val);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &val, &b);
        for(auto iter = lt.begin(); iter != lt.end(); iter++)
        {
            if(*iter == b)
            {
                iter++;
                lt.insert(iter, val);
                break;
            }
        }
    }
    scanf("%d", &val);

    for(auto iter = lt.begin(); iter != lt.end(); iter++)
    {
        if(*iter != val)
        {
            printf("%d ", *iter);
        }
    }
    printf("\n");

    return 0;
}