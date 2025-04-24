#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main()
{
    char str[32];
    uint32_t ip;

    scanf("%s", str);
    int len = strlen(str);
    str[len] = '.';
    len++;
    for(int i = 0, s = 0; i < len; i++)
    {
        if(str[i] == '.')
        {
            str[i] = '\0';
            uint32_t sub_ip = 0;
            sscanf(str + s, "%u", &sub_ip);
            ip = (ip << 8) + (sub_ip & 0xFF);
            s = i + 1;
        }
    }
    printf("%u\n", ip);

    scanf("%d", &ip);
    for(int i = 3; i > 0; i--)
    {
        printf("%d.", (ip >> (i * 8)) & 0xFF);
    }
    printf("%d\n", ip & 0xFF);
}