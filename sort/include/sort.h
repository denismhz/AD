#ifndef _SORT_
#define _SORT_
template<class T>
class Sort
{
    public:
        Sort(int (*compare)(T, T));
        void bubbleSort(T*, int);
        void selectionSort(T*, int);
    private:
        void swap(T&, T&);
        int (*compare)(T,T);
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
            if(arr[j] > arr[j+1]){ 
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
            if(arr[largest] < arr[j]) largest = j;
        }
        swap(arr[i], arr[largest]);
        largest = 0;
    }
}

#endif
