#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIMIT 100000

int main(){
    int number;
    srand(time(NULL));
    FILE *fptr;
    fptr = fopen("numbers_5.dat","w");
    for(int i=0;i<LIMIT;i++){
        number = rand()%1000;
        fprintf(fptr,"%d\n",number);
    }
    fclose(fptr);
    return 0;
}
