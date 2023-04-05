#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#define LIMIT 100000

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    int temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        //swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    struct timeval stop, start;
    int i;
    int random_number;
    int arr[LIMIT];
    FILE *fp;

    fp =fopen ("numbers_1.dat","w");
    srand((unsigned)time(0));
    i=0;
    do
    {
        random_number = (int) (rand()%1000) ;
        //printf("%d\n", random_number);
        fprintf(fp, "%d\n", random_number);
        i++;
    }while (i<LIMIT);
    fclose(fp);
fp =fopen ("numbers_1.dat","r");
    i=0;
    do
    {
        fscanf(fp, "%d", &arr[i]);
        //printf("%d\n",arr[i]);
        i++;
    }while (i<LIMIT);
    fclose(fp);
    gettimeofday(&start, NULL);
    selection_sort(arr,i);
    gettimeofday(&stop, NULL);

    printf("\n\nFor Selection Sort");
    printf("\nstart %lu", start.tv_sec);
    printf("\nstop %lu", stop.tv_sec);
    printf("\nDifference %lu", stop.tv_sec - start.tv_sec);


    return 0;
}
