#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        long long int x1, x2, x3, y1, y2, y3, r1, r2, r3, amount = 0;
        scanf("%lld%lld%lld", &x1, &y1, &r1);
        scanf("%lld%lld%lld", &x2, &y2, &r2);
        scanf("%lld%lld%lld", &x3, &y3, &r3);
        long long int x = x1 - r1;
        while (x <= x1 + r1)
        {
            long long int y = y1 - r1;
            while (y <= y1 + r1)
            {
                if (((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r1 * r1 && (x - x2) * (x - x2) + (y - y2) * (y - y2) <= r2 * r2) && (x - x3) * (x - x3) + (y - y3) * (y - y3) <= r3 * r3)
                    amount++;
                else if ((x - x2) * (x - x2) + (y - y2) * (y - y2) > r2 * r2)
                {
                    if ((x - x3) * (x - x3) + (y - y3) * (y - y3) > r3 * r3)
                    {
                        if ((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r1 * r1)
                            amount++;
                    }
                }

                y++;
            }

            x++;
        }

        x = x2 - r2;
        while (x <= x2 + r2)
        {
            long long int y = y2 - r2;
            while (y <= y2 + r2)
            {

                if ((x - x1) * (x - x1) + (y - y1) * (y - y1) > r1 * r1)
                {
                    if ((x - x3) * (x - x3) + (y - y3) * (y - y3) > r3 * r3)
                    {
                        if ((x - x2) * (x - x2) + (y - y2) * (y - y2) <= r2 * r2)
                            amount++;
                    }
                }
                y++;
            }
            x++;
        }

        x = x3 - r3;
        while (x <= x3 + r3)
        {
            long long int y = y3 - r3;
            while (y <= y3 + r3)
            {

                if ((x - x1) * (x - x1) + (y - y1) * (y - y1) > r1 * r1)
                {
                    if ((x - x2) * (x - x2) + (y - y2) * (y - y2) > r2 * r2)
                    {
                        if ((x - x3) * (x - x3) + (y - y3) * (y - y3) <= r3 * r3)
                            amount++;
                    }
                }
                y++;
            }

            x++;
        }

        printf("%lld\n", amount);
        n--;
    }
}