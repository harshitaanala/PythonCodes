#include <stdio.h>
#include <conio.h>
void main()
{
    int n,m;
    int i,j;
    printf("Enter the number of items:");
    scanf("%d",&n);
    printf("Enter the weight of the bag:");
    scanf("%d",&m);
    int p[n];
    int w[n];
    int k[n+1][m+1];
    printf("Enter the profits for each item:");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the weights of each item:");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j]=0;
            }
            else if(w[i]<=j)
            {
                if(k[i-1][j]>p[i]+k[i-1][j-w[i]])
                {
                    k[i][j]=k[i-1][j];
                }
                else if(k[i-1][j]<p[i]+k[i-1][j-w[i]])
                {
                    k[i][j]=p[i]+k[i-1][j-w[i]];
                }
            }
            else
            {
                k[i][j]=k[i-1][j];
            }
        }
    }
    printf("The maximum profit is: %d",k[n][m]);
}
