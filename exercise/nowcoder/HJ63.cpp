#include <stdio.h>
#include <string.h>

const int MAX_N = 1000 + 10;

int main()
{
    char str[MAX_N];
    int n;
    int max_n;
    int max_ind;

    scanf("%s", str);
    scanf("%d", &n);
    max_n = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'G' || str[i] == 'C')
        {
            max_n++;
        }
    }

    int len = strlen(str);
    int cur_n = max_n;
    max_ind = 0;
    for(int i = n; i < len; i++)
    {
        if(str[i - n] == 'G' || str[i - n] == 'C')
        {
            cur_n--;
        }
        if(str[i] == 'G' || str[i] == 'C')
        {
            cur_n++;
        }
        if(cur_n > max_n)
        {
            max_n = cur_n;
            max_ind = i - n + 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%c", str[max_ind + i]);
    }
    printf("\n");

    return 0;
}