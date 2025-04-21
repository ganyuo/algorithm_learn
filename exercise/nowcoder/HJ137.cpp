#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 1e5 + 10;

int count, n, k;
int num[MAX_N];

int64_t get_max_range(int &left, int &right)
{
    int64_t max_sum = num[0];
    left = 0, right = 1;
    int64_t sum = num[0];
    int l = 0, r = 1;
    while(r < n)
    {
        if(sum <= 0)
        {
            l = r;
            r = l + 1;
            sum = num[l];
        }
        else
        {
            sum += num[r];
            r++;
        }
        if(max_sum < sum)
        {
            max_sum = sum;
            left = l;
            right = r;
        }
    }
    return max_sum;
}

int64_t get_min_range(int &left, int &right)
{
    int64_t min_sum = num[0];
    left = 0, right = 1;
    int64_t sum = num[0];
    int l = 0, r = 1;
    while(r < n)
    {
        if(sum >= 0)
        {
            l = r;
            r = l + 1;
            sum = num[l];
        }
        else
        {
            sum += num[r];
            r++;
        }
        if(min_sum > sum)
        {
            min_sum = sum;
            left = l;
            right = r;
        }
    }
    return min_sum;
}

int main()
{
    int64_t ans;

    scanf("%d", &count);
    while(count--)
    {
        scanf("%d %d", &n, &k);
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            ans += num[i];
        }

        int left, right;
        if(k >= 1)
        {
            int64_t sum = get_max_range(left, right);
            ans += sum * (int64_t)(k - 1);
            memset(num + left, 0, (right - left) * sizeof(int));
            sum = get_min_range(left, right);
            ans += sum * (int64_t)(k - 1);
        }
        else
        {
            int64_t sum = get_min_range(left, right);
            ans += sum * (int64_t)(k - 1);
            memset(num + left, 0, (right - left) * sizeof(int));
            sum = get_max_range(left, right);
            ans += sum * (int64_t)(k - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
