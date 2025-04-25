#include <stdio.h>
#include <string.h>

const int MAX_N = 10000 + 10;

int main()
{
    char str1[MAX_N];
    char str2[MAX_N];
    char ans[MAX_N];

    scanf("%s", str1);
    scanf("%s", str2);

    int ind1 = strlen(str1) - 1;
    int ind2 = strlen(str2) - 1;
    int sf = 0;
    int ind = 0;
    while(ind1 >= 0 || ind2 >= 0)
    {
        int num1 = 0;
        if(ind1 >= 0)
        {
            num1 = str1[ind1] - '0';
            ind1--;
        }
        int num2 = 0;
        if(ind2 >= 0)
        {
            num2 = str2[ind2] - '0';
            ind2--;
        }
        num1 = num1 + num2 + sf;
        sf = num1 / 10;
        ans[ind] = '0' + num1 % 10;
        ind++;
    }
    if(sf > 0)
    {
        ans[ind] = '0' + sf;
        ind++;
    }
    for(int i = ind - 1; i >= 0; i--)
    {
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}
