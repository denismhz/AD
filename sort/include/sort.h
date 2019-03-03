#ifndef _SORT_
#define _SORT_
#include <string>

void prarr(int *arr, int s, int e);
int pow(int, int);
int getDigit(int, std::string, int);
int getChar(int, std::string);

template<class T>
class Sort
{
    public:
        Sort();
        Sort(int (*compare)(T, T));
        void bubbleSort(T*, int); //works
        void selectionSort(T*, int); //works
        void insertionSort(T*, int); //works
        void shellSort(T*, int); //works
        void mergeSort(T*, int, int); //works
        void countingSort(int*, int);
        void quickSort(T*, int, int); //works
        void radixSort(T*, std::string[], int, int);
    private:
        void swap(T&, T&);
        T getMax(T*, int);
        T getMin(T*, int);
        int (*compare)(T,T);
        void merge(T*, int, int, int);
        int partition(T*, int, int);
        void radixSingleSort(T*, std::string[], int, int, int, int);
};

int getDigit(int pos, std::string val, int radix){
    return val[pos]-'a';
}

int getChar(int pos, std::string val){
    return val[pos]-'a';
}

int pow(int a, int b){
    int e = 1;
    for(int i = 1; i <= b; i++){
        e*=a;
    }
    return e;
}

template<typename T>
Sort<T>::Sort(){}

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
T Sort<T>::getMax(T* arr, int l){
    int max = 0;
    for(int i = 0; i < l; i++){
        if(compare(arr[i], max) == 1) max = arr[i];
    }
    return max;
}

template<typename T>
T Sort<T>::getMin(T* arr, int l){
    int min = arr[0];
    for(int i = 0; i < l; i++){
        if(compare(arr[i], min) == -1) min = arr[i];
    }
    return min;
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
    T newElem = 0;
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

void insertionSortRec(int* arr, int l){
    if(l <= 1) return;
    insertionSortRec(arr, l-1);
    int newElem = arr[l-1];
    int i = 0;
    for(i = l-1; i > 0 && arr[i-1] > newElem; i--){
        arr[i] = arr[i-1];
    }
    arr[i] = newElem;
}

template<typename T>
void Sort<T>::shellSort(T* arr, int l){
    for(int gap = l/2; gap > 0; gap/=2){
        for(int i = gap; i < l; i++){
            T newElem = arr[i];
            int j = i;
            while(j >= gap && compare(arr[j-gap], newElem) == 1){
                arr[j] = arr[j-gap];
                j -= gap;           
            }
            arr[j] = newElem;
        }
    }
}

//@end length-1 start 0
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

template<typename T>
void Sort<T>::countingSort(int* arr, int l){
    int k = 0;
    int max = getMax(arr, l);
    int min = getMin(arr, l);
    int tmp[(max-min)+1] = {0};
    for(int i = 0; i < l; i++){
        tmp[arr[i]-min]++;
    }
    for(int i = min; i <= max; i++){
        while(tmp[i-min] > 0){
            arr[k++] = i;
            tmp[i-min]--;
        }
    }
}

template<typename T>
void Sort<T>::quickSort(T* arr, int start, int end){
    if(end <= start) return;
    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex);
    quickSort(arr, pivotIndex+1, end);   
}

template<typename T>
int Sort<T>::partition(T* arr, int start, int end){
    T pivot = arr[(start+end)/2];
    int i = start-1;
    int j = end+1;
    while(1){
        do i++;
        while(compare(arr[i], pivot) == -1);
        do j--;
        while(compare(arr[j], pivot) == 1);
        if(i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

char toLowerCase(char c){
    if(c >='A' && c<='Z'){
        return c+32;
    }
    return c;
}

template<typename T>
void Sort<T>::radixSort(T* out, std::string a[], int radix, int l){
    unsigned long int maxlength = 0;
    //add padding
    for(int i = 0; i < l; i++){
        if(a[i].length() > maxlength) maxlength = a[i].length();
    }
    for(int i = 0; i < l; i++){
      a[i].resize(maxlength, 'a');
      //to lower case
      for(char& c: a[i]){
        c = toLowerCase(c);
      }
    }
    for(unsigned long int i = 0; i < maxlength; i ++){
        radixSingleSort(out, a, i,maxlength, radix, l);
    }
}

template<typename T>
void Sort<T>::radixSingleSort(T* out,std::string arr[], int pos, int width, int radix, int l){
    int countArr[radix] = {0};
    int countArr2[radix] = {0};
    for(int i = 0; i < l; i++){
        countArr[getChar((width-1)-pos, arr[i])]++;
        countArr2[getChar((width-1)-pos, arr[i])]++;
    }
    //Adjust countArray
    for(int i = 1; i < radix; i++) countArr[i] += countArr[i-1];
    for(int i = 1; i < radix; i++) countArr2[i] += countArr2[i-1];
    std::string tmp[l];
    T t[l];
    for(int tmpIndex = l-1; tmpIndex >= 0; tmpIndex--){
        tmp[--countArr[getChar((width-1)-pos, arr[tmpIndex])]] = arr[tmpIndex];
        t[--countArr2[getChar((width-1)-pos, arr[tmpIndex])]] = out[tmpIndex];
    }
    
    for(int i = 0; i < l; i++){
        arr[i] = tmp[i];
        out[i] = t[i];
    }
}

#endif
