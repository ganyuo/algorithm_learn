#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAX_N = 1000 + 10;
// const int MAX_N = 10;

int main()
{
    char str1[MAX_N];
    char str2[MAX_N];
    int dp[MAX_N];

    scanf("%s", str1 + 1);
    scanf("%s", str2 + 1);
    int len1 = strlen(str1 + 1);
    int len2 = strlen(str2 + 1);

    dp[0] = 0;
    for(int i = 1; i <= len1; i++)
    {
        dp[i] = i;
    }
    
    for(int i = 1; i <= len2; i++)
    {
        int pre = dp[0];
        dp[0] = i;
        for(int j = 1; j <= len1; j++)
        {
            int temp = dp[j];
            if(str1[j] == str2[i])
            {
                dp[j] = pre;
            }
            else
            {
                dp[j] = std::min(dp[j], dp[j - 1]);
                dp[j] = std::min(dp[j], pre);
                dp[j]++;
            }
            pre = temp;
        }
    }
    printf("%d\n", dp[len1]);

    return 0;
}
