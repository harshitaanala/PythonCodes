#include <stdio.h>
#define inf 9999
void floyd_algorithm(int n,int a[n][n])
{
    int k,i,j;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                }
                else if(a[i][j]<(a[i][k]+a[k][j]))
                {
                    a[i][j]=a[i][j];
                }
            }
        }
    }
    printf("The shortest paths between nodes are:");
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
        {
            printf("%d",a[i][j]);
        }
    }

}
void main()
{
    int i,j;
    int n;
    printf("Enter the size of matrix:");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the elements:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    floyd_algorithm(n,a);
}
