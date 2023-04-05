#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define LIMIT 100000
int Partition(int arr[],int l,int h)
{
    int temp,temp1;
    int pivot=arr[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
           i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp1=arr[l];
    arr[l]=arr[j];
    arr[j]=temp1;
    return j;
}

void QuickSort(int arr[],int l,int h)
{
    int loc;
        if(l<h)
        {
            loc=Partition(arr,l,h);
            QuickSort(arr,l,loc-1);
            QuickSort(arr,loc+1,h);
        }
}
void Merge(int arr[],int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=0;
    int b[LIMIT];
    while(i<=mid && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            b[k++]=arr[i];
            i++;
        }
        else
        {
            b[k++]=arr[j];
            j++;
        }
    }
    if(i>mid)
    {
        while(j<=h)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    for(i=l,k=0;i<=h;i++,k++)
    {
        arr[i]=b[k];
    }
}
void MergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
       int mid=(l+h)/2;
       MergeSort(arr,l,mid);
       MergeSort(arr,mid+1,h);
       Merge(arr,l,mid,h);
    }
}
int main()
{
    struct timeval stop, start;
    int i;
    int random_number;
    int arr[LIMIT];
    FILE *fp;
    fp =fopen("numbers_5.dat","w");
    srand(time(NULL));
    i=0;
    do
    {
        random_number = (int) (rand()%1000) ;

        fprintf(fp, "%d\n", random_number);
        i++;
    }while (i<LIMIT);
    fclose(fp);
    printf("Number created succesfully\n");
    fp =fopen("numbers_5.dat","r");
    i=0;
    do
    {
        fscanf(fp, "%d", &arr[i]);
        i++;
    }while(i<LIMIT);
    fclose(fp);
    printf("Starting merge sort\n");
    gettimeofday(&start, NULL);
    MergeSort(arr,0,LIMIT-1);
    gettimeofday(&stop, NULL);
    if(stop.tv_usec<start.tv_usec){
    stop.tv_sec--;
    stop.tv_usec+=1000000;
    }
    float diff=stop.tv_usec-start.tv_usec;
    diff=diff/1000000.0;
    printf("After merge sort");
    printf("\n\nFor Merge Sort");
    printf("\nstart %lu seconds %lu microseconds", start.tv_sec,start.tv_usec);
    printf("\nstop %lu seconds %lu microseconds", stop.tv_sec,stop.tv_usec);
    printf("\nDifference %f", stop.tv_sec - start.tv_sec+diff);


    fp =fopen("numbers_5.dat","r");
    i=0;
    do
    {
        fscanf(fp, "%d", &arr[i]);
        i++;
    }while(i<LIMIT);
    fclose(fp);
    gettimeofday(&start, NULL);
    QuickSort(arr,0,LIMIT-1);
    gettimeofday(&stop, NULL);
    if(stop.tv_usec<start.tv_usec){
    stop.tv_sec--;
    stop.tv_usec+=1000000;
    }
    diff=stop.tv_usec-start.tv_usec;
    diff=diff/1000000.0;
    printf("\n\nFor QuickSort");
    printf("\nstart %lu seconds %lu microseconds", start.tv_sec,start.tv_usec);
    printf("\nstop %lu seconds %lu microseconds", stop.tv_sec,stop.tv_usec);
    printf("\nDifference %f", stop.tv_sec - start.tv_sec+diff);
    return 0;
}
