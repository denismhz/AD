#include "../include/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int acompare(int a, int b){
  return a == b ? 0 : ((a < b) ? -1 : 1);
}

int test(int* p, int l){
    for(int i = 0; i < l; i++){
        if(p[i] > p[i+1] && i+1 < l) return -1;
    }
    return 1;
}

int main(){
    int (*fct)(int, int) = acompare;
    Sort<int>* s = new Sort<int>(fct);
    int a[10] = {0};
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }
    for(int i = 0; i < 10; i++){
        printf("%d,", a[i]); 
    }
    printf("\n");
    s->mergeSort(a, 0, 9);

    for(int i = 0; i < 10; i++){
        printf("%d,", a[i]); 
    }
    printf("\n");
    printf("%d\n", test(a, 10));
    return 0;
}
