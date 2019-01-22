#include <stdio.h>
int main()
{
    int t, i, n, sum1 = 0;
    scanf("%d",t);
    while (t--)
    {
        scanf("%d",n);
        sum1=0;
        for (i = 3; i < n; i++)
        {
            if ((i % 3 == 0) || (i % 5 == 0))
            {
                sum1 = sum1 + i;
            }
        }
        printf("%d\n",sum1);

    }
    return(0);
}
