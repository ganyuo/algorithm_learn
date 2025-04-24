#include <stdio.h>

int main()
{
    double h, route;

    scanf("%lf", &h);
    route = h;
    for(int i = 1; i < 5; i++)
    {
        route += h;
        h = h / 2;
    }
    printf("%.8lf\n%.8lf\n", route, h / 2);

    return 0;
}