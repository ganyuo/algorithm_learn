#include <stdio.h>
#include <string.h>

const int MAX_N = 100 + 10;

int main()
{
    bool book[26];
    char encode[MAX_N];
    char str[MAX_N];

    scanf("%s", encode);
    scanf("%s", str);

    int len = strlen(encode);
    memset(book, false, sizeof(book));
    int k = 0;
    for(int i = 0; i < len; i++)
    {
        if(book[encode[i] - 'a'] == false)
        {
            book[encode[i] - 'a'] = true;
            encode[k] = encode[i];
            k++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(book[i] == false)
        {
            encode[k] = 'a' + i;
            k++;
        }
    }
    // encode[k] = '\0';
    // printf("%s\n", encode);

    len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        str[i] = encode[str[i] - 'a'];
    }
    printf("%s\n", str);

    return 0;
}
