#include <stdio.h>
int main() {
   int arr[10]={6,12,0,18,11,99,55,45,34,2};
   int n=10;
   int i, j, position, swap;
   for (i = 0; i < (n - 1); i++) {
      position = i;
      for (j = i + 1; j < n; j++) {
         if (arr[position] > arr[j])
            position = j;
      }
      if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }
   for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
   return 0;
}

#include <stdio.h>
#include <math.h>
int main() {
    int arr[] = {6,12,0,18,11,99,55,45,34,2};
    int n=10;
    int i, key, j;
    for(i=0;i<n;i++0){
        key = arr[i];
        j = i-1;
    }
    while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        j = j-1;
    }
    arr[j+1] = key;

    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

