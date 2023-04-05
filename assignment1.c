#include<stdlib.h>
#include<stdio.h>

int binary_search(int arr[], int target, int start, int end){

    if(start <= end){

        int pivot = start + ((2*(end-start))/3);

        if(arr[pivot]==target){
            return pivot;
        }

        if(arr[pivot]>target){
            return binary_search(arr, target, start, pivot-1);
        }

        return binary_search(arr, target, pivot+1, end);
    }
    return -1;
}


int main(void)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int result =binary_search(arr, x, 0, n-1);
    printf("%d",result);
    return 0;
}
