#include <stdio.h>
#include <string.h>
#include <stdint.h>

int count, n, k;
int num;
int64_t ans;

int main()
{
    scanf("%d", &count);
    while(count--)
    {
        scanf("%d %d", &n, &k);
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            ans += num;
        }
        printf("%lld\n", ans * k);
    }
    return 0;
}
