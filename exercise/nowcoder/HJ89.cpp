/* AC */

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

struct card_t
{
    int num;
    std::string str;
};

int get_num(std::string str)
{
    if ('2' <= str[0] && str[0] <= '9')
    {
        return str[0] - '0';
    }
    else if (str == "10")
    {
        return 10;
    }
    else if (str == "A")
    {
        return 1;
    }
    else if (str == "J")
    {
        return 11;
    }
    else if (str == "Q")
    {
        return 12;
    }
    else if (str == "K")
    {
        return 13;
    }
    return -1;
}


card_t card[4];
bool visit[4];
std::string ans;

bool dfs(std::string str, int cal, int dep)
{
    std::string temp;

    if (dep >= 4)
    {
        if (cal == 24)
        {
            ans = str;
            return true;
        }
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (visit[i] == true)
        {
            continue;
        }
        visit[i] = true;
        temp = str + "*" + card[i].str;
        if (dfs(temp, cal * card[i].num, dep + 1) == true)
        {
            return true;
        }
        temp = str + "/" + card[i].str;
        if (dfs(temp, cal / card[i].num, dep + 1) == true)
        {
            return true;
        }
        // if (cal != 0)
        // {
        //     temp = card[i].str + "/" + str;
        //     if (dfs(temp, card[i].num / cal, dep + 1) == true)
        //     {
        //         return true;
        //     }
        // }
        temp = str + "+" + card[i].str;
        if (dfs(temp, card[i].num + cal, dep + 1) == true)
        {
            return true;
        }
        temp = str + "-" + card[i].str;
        if (dfs(temp, cal - card[i].num, dep + 1) == true)
        {
            return true;
        }
        visit[i] = false;
    }
    return false;
}

int main()
{
    bool flag = false;
    for(int i = 0; i < 4; i++)
    {
        std::cin >> card[i].str;
        card[i].num = get_num(card[i].str);
        if(card[i].num == -1)
        {
            flag = true;
        }
    }
    if(flag == true)
    {
        printf("ERROR\n");
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        ans = std::string(card[i].str);
        memset(visit, false, sizeof(visit));
        visit[i] = true;
        if (dfs(ans, card[i].num, 1) == true)
        {
            printf("%s\n", ans.c_str());
            return 0;
        }
    }

    printf("NONE\n");
    return 0;
}