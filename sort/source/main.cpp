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

void prarr(int *arr, int s, int e){
  for(int i = s; i <= e; ++i)
    printf("%d%s", arr[i], i == e ? "\n" : ", ");
}

int main(){
    int (*fct)(int, int) = acompare;
    Sort<int>* s = new Sort<int>(fct);
    int a[10] = {0};
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }
    prarr(a, 0, 9);
    printf("\n");
    s->countingSort(a, 10);
    prarr(a, 0,9);
    printf("\n");
    printf("%d\n", test(a, 10));
    return 0;
}
