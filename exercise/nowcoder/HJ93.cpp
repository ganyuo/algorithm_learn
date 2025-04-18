#include <stdio.h>
#include <string.h>

// const int MAX_NUM = 50 * 1000 + 100;

// bool val[MAX_NUM];

int main()
{
    int n, m, temp;
    int sp, sum;
    int num[60];
    int sl;
    int set[60];

    scanf("%d", &n);
    m = 0;
    sp = 0;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        // temp += 510;
        sum += temp;
        if(temp % 5 == 0)
        {
            sp += temp;
        }
        else if(temp % 3 != 0)
        {
            num[m] = temp;
            m++;
        }
    }
    if(sum & 1)
    {
        printf("false\n");
        return 0;
    }


    bool ans = false;
    sum /= 2;
    if(n == 0 || sp == sum)
    {
        printf("true\n");
        return 0;
    }
    // memset(val, false, sizeof(val));
    // val[sp] = true;
    sl = 1;
    set[0] = sp;
    for(int i = 0; i < m; i++)
    {
        int sl_cn = sl;
        for(int j = 0; j < sl_cn; j++)
        {
            int new_num = set[j] + num[i];
            if(new_num == sum)
            {
                ans = true;
                break;
            }
            bool flag = false;
            for(int k = 0; k < sl; k++)
            {
                if(set[k] == new_num)
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {
                set[sl] = new_num;
                sl++;
            }
            // if(val[new_num] == false)
            // {
            //     val[new_num] = true;
            // }
        }
        if(ans == true)
        {
            break;
        }
    }

    if(ans == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}