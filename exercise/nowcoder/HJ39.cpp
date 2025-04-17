#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 100;

uint8_t g_ip[4];

bool check_ip(char *str, uint32_t &ip)
{
    uint32_t temp;
    int s = 0, count = 0;

    ip = 0;
    int len = strlen(str);
    for(int i = 0; i <= len && str[i] != '\n'; i++)
    {
        if((str[i] < '0' || '9' < str[i]) && str[i] != '.')
        {
            return false;
        }
        if(str[i] == '.')
        {
            str[i] = '\0';
            sscanf(str + s, "%d", &temp);
            if (temp > 255)
            {
                return false;
            }
            g_ip[count] = (uint8_t)temp;
            ip += temp;
            ip <<= 8;
            s = i + 1;
            count++;
        }
    }
    if (count != 3)
    {
        return false;
    }
    sscanf(str + s, "%d", &temp);
    if (temp > 255)
    {
        return false;
    }
    g_ip[3] = (uint8_t)temp;
    ip += temp;
    return true;
}

int main()
{
    char mask[MAX_N];
    char ip1[MAX_N];
    char ip2[MAX_N];

    uint32_t mask_i, ip1_i, ip2_i;

    while (fgets(mask, MAX_N, stdin) != NULL &&
           fgets(ip1, MAX_N, stdin) != NULL &&
           fgets(ip2, MAX_N, stdin) != NULL)
    {
        if (check_ip(mask, mask_i) == false ||
            check_ip(ip1, ip1_i) == false ||
            check_ip(ip2, ip2_i) == false)
        {
            printf("1\n");
        }
        else
        {
            uint32_t temp = mask_i;
            bool flag = true;
            bool zero = true;
            for (int i = 0; i < 32; i++)
            {
                if (temp & 1)
                {
                    zero = false;
                }
                if ((temp & 0x01) == 0 && zero == false)
                {
                    flag = false;
                    break;
                }
                temp >>= 1;
            }
            if (flag == false)
            {
                printf("1\n");
                continue;
            }

            uint32_t ip1_prefix = ip1_i & mask_i;
            uint32_t ip2_prefix = ip2_i & mask_i;
            if (ip1_prefix == ip2_prefix)
            {
                printf("0\n");
            }
            else
            {
                printf("2\n");
            }
        }
    }
    return 0;
}


/*

255.255.255.0
192.168.224.256
192.168.10.4
255.0.0.0
193.194.202.15
232.43.7.59
255.255.255.0
192.168.0.254
192.168.0.1

*/
