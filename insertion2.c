#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#define LIMIT 100000

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    struct timeval stop, start;
    int i;
    int random_number;
    int arr[LIMIT];
    FILE *fp;

    fp =fopen ("numbers_2.dat","w");
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

    // Round 1

    fp =fopen ("numbers_2.dat","r");
    i=0;
    do
    {
        fscanf(fp, "%d", &arr[i]);
        //printf("%d\n",arr[i]);
        i++;
    }while (i<LIMIT);
    fclose(fp);
    gettimeofday(&start, NULL);
    insertion_sort(arr,i);
    gettimeofday(&stop, NULL);
    printf("\n\nFor Insertion Sort");
    printf("\nstart %lu", start.tv_sec);
    printf("\nstop %lu", stop.tv_sec);
    printf("\nDifference %lu", stop.tv_sec - start.tv_sec);

    return 0;

}

