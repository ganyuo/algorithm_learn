#include <stdio.h>
#include <algorithm>

const int MAX_N = 2e5 + 10;

int count, n, m;
int num[MAX_N];
int sn[MAX_N];

inline int search(int numb)
{
    int left = 0;
    int right = n;
    int mid;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(sn[mid] == numb)
        {
            return mid;
        }
        else if(sn[mid] < numb)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &count);
    while (count --)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", num + i);
            sn[i] = num[i];
        }

        std::sort(sn, sn + n);
        bool sam = false;
        for(int i = 1; i < n; i++)
        {
            if(sn[i] == sn[i - 1])
            {
                sam = true;
                break;
            }
        }
        if(sam == true)
        {
            printf("NO\n");
            continue;
        }

        int left = 0;
        while(left <= n - m)
        {
            int sl = search(num[left]);
            bool flag = true;
            for(int len = 1; len < m; len++)
            {
                if(sl + len >= n || num[left + len] != sn[sl + len])
                {
                    flag = false;
                    left += len;
                    break;
                }
            }
            if(flag == true)
            {
                break;
            }
        }
        int right = n - 1;
        while(right >= m - 1)
        {
            int ll = search(num[right]);
            bool flag = true;
            for(int len = 1; len < m; len++)
            {
                if(ll + len >= n || num[right - len] != sn[ll + len])
                {
                    flag = false;
                    right -= len;
                    break;
                }
            }
            if(flag == true)
            {
                break;
            }
        }

        if(left <= n - m || right >= m - 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
