#ifndef _SORT_
#define _SORT_
#include <stdlib.h>
#include <stdio.h>
template<class T>
class Sort
{
    public:
        Sort(int (*compare)(T, T));
        void bubbleSort(T*, int);
        void selectionSort(T*, int);
        void insertionSort(T*, int);
        void shellSort(T*, int);
        void mergeSort(T*, int, int);
    private:
        void swap(T&, T&);
        int (*compare)(T,T);
        void merge(T*, int, int, int);
};

template<typename T>
Sort<T>::Sort(int (*compare)(T,T)){
    this->compare = compare;
}

template<typename T>
void Sort<T>::swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void Sort<T>::bubbleSort(T* arr, int l){
    for(int i = l-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(compare(arr[j], arr[j+1]) == 1){ 
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

template<typename T>
void Sort<T>::selectionSort(T* arr, int l){
    int largest = 0;
    for(int i = l-1; i >= 0; i--){
        for(int j = 1; j <= i; j++){
            if(compare(arr[largest], arr[j])==-1) largest = j;
        }
        swap(arr[i], arr[largest]);
        largest = 0;
    }
}

template<typename T>
void Sort<T>::insertionSort(T* arr, int l){
    int newElem = 0;
    for(int i = 1; i < l; i++){
        newElem = arr[i];
        for(int j = i-1; j >= 0; j--){
           if(compare(newElem, arr[j])==-1) {
               arr[j+1] = arr[j];
               arr[j] = newElem;
           }
        }
    }    
}

template<typename T>
void Sort<T>::shellSort(T* arr, int l){
    for(int gap = l/2; gap > 0; gap/=2){
        for(int i = gap; i < l; i++){
            int newElem = arr[i];
            int j = i;
            while(j >= gap && arr[j-gap] > newElem){
                arr[j] = arr[j-gap];
                j -= gap;           
            }
            arr[j] = newElem;
        }
    }
}

//template<typename T>
/*void prarr(int *arr, int s, int e, char *ex){
  printf(ex);
  for(int i = s; i <= e; ++i)
    printf("%d%s", arr[i], i == e ? "\n" : ", ");
}*/

template<typename T>
void Sort<T>::mergeSort(T* arr, int start, int end){
    if(end - start < 1 ) return;
    int mid = start+(end-start)/2;
    mergeSort(arr, start, mid); // 0-4; (0-2; (0-1-, 2-2-), 3-4; (3-3-, 4-4-))
    mergeSort(arr, mid + 1, end); // 5-9; (5-7, 8-9)  
    merge(arr, start, mid, end);
}

template<typename T>
void Sort<T>::merge(T* arr, int start, int mid, int end){
    int i = start;
    int j = mid + 1; 
    int index = 0;
    T tmp[end - start + 1];
    while(i <= mid && j <= end)
      if(compare(arr[i], arr[j]) == -1)
            tmp[index++] = arr[i++];
	else
            tmp[index++] = arr[j++];

    
    //Copy left over elems
    while(i <= mid)
        tmp[index++] = arr[i++];

    while(j <= end)
      tmp[index++] = arr[j++];
    
    //Copy tmp to arr
    for(int i = start; i <= end; i++)
       arr[i] = tmp[i - start];
}

#endif
