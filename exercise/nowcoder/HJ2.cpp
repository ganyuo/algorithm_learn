#include <stdio.h>

int main()
{
    char str[1000 + 10];
    char ch;
    int count = 0;

    fgets(str, 1010, stdin);
    scanf("%c", &ch);
    if('A' <= ch && ch <= 'Z')
    {
        ch = ch - 'A' + 'a';
    }
    for(int i = 0; str[i] != '\n'; i++)
    {
        if('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i]  - 'A' + 'a';
        }
        if(str[i] == ch)
        {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}