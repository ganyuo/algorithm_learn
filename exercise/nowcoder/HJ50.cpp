#include <stdio.h>
#include <string.h>

const int MAX_N = 1e3 + 10;
// const int MAX_N = 50;

int calculate(int a, int b, char opt)
{
    if(opt == '+')
    {
        return a + b;
    }
    else if(opt == '-')
    {
        return a - b;
    }
    else if(opt == '*')
    {
        return a * b;
    }
    else if(opt == '/')
    {
        return a / b;
    }
    return 0;
}

int main()
{
    int len, opt_top, num_top;
    char str[MAX_N];
    char opt[MAX_N];
    int num[MAX_N];
    int prior[128];

    scanf("%s", str);
    len = strlen(str);
    str[len] = 'e';
    prior[0] = 0;
    prior['e'] = 1;
    prior['{'] = 2;
    prior['['] = 3;
    prior['('] = 4;
    prior['+'] = 5;
    prior['-'] = 5;
    prior['*'] = 6;
    prior['/'] = 6;
    prior['}'] = 7;
    prior[']'] = 8;
    prior[')'] = 9;


    opt_top = 0;
    opt[0] = 0;
    num_top = -1;
    int i = 0;
    while(opt[opt_top] != 'e')
    {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            opt_top++;
            opt[opt_top] = str[i];
            i++;
        }
        int temp = 0;
        while(i < len  && '0' <= str[i] && str[i] <='9')
        {
            temp = temp * 10 + (str[i] - '0');
            i++;
        }
        num_top++;
        num[num_top] = temp;

        while(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            while(opt[opt_top] != '(' && opt[opt_top] != '[' && opt[opt_top] != '{')
            {
                int b = num[num_top--];
                num[num_top] = calculate(num[num_top], b, opt[opt_top]);
                opt_top--;
            }
            opt_top--;
            i++;
        }

        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == 'e')
        {
            while(prior[str[i]] <= prior[opt[opt_top]])
            {
                int b = num[num_top--];
                num[num_top] = calculate(num[num_top], b, opt[opt_top]);
                opt_top--;
            }
            opt_top++;
            opt[opt_top] = str[i];
            i++;
        }
    }
    printf("%d\n", num[num_top]);

    return 0;
}