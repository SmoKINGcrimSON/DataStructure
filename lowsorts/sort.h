#ifndef SORT_H
#define SORT_H
namespace sorts{
    template<typename V>
    void BubbleSort(V*, int);
    template<typename V>
    void SelectionSort(V*, int);
    template<typename V>
    void InsertionSort(V*, int);
}

template<typename V>
void sorts::BubbleSort(V* array, int size){
    V temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

template<typename V>
void sorts::SelectionSort(V* array, int size){
    int min;
    V temp;
    for(int i = 0; i < size - 1; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            if(array[min] > array[j]){
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

template<typename V>
void sorts::InsertionSort(V* array, int size){
    V temp;
    for(int i = 1; i < size; i++){
        temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
#endif