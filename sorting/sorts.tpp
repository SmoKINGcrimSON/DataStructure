#include "sorts.h"

//merged sort
template<typename V>
void sorts::MergedSort(V* array, const int size){
    //if array its onle of one element
    if(size <= 1) return;
    //create variable lenght
    int lenght = size;
    //declared size of left and right array
    int sizeLeft = size/2;
    int sizeRight = lenght - sizeLeft;
    //declared left and right array
    V leftArray[sizeLeft];
    V rightArray[sizeRight];
    //fill left and right array
    int j = 0; //index for right array
    for(int i = 0; i < lenght; i++){
        if(i < sizeLeft){
            leftArray[i] = array[i];
        }
        else{
            rightArray[j] = array[i];
            j++;
        }
    }
    //recursivity
    MergedSort(leftArray, sizeLeft);
    MergedSort(rightArray, sizeRight);
    //merged
    Merge(array, lenght, leftArray, sizeLeft, rightArray, sizeRight);
}

template<typename V>
void sorts::Merge(V* array, const int size, V* arrayLeft, const int sizeL, V* arrayRight, const int sizeR){

    //declare size of left and right
    int leftsize = sizeL;
    int rightsize = sizeR;
    //fill the original array with the elemnts of the other arrays sorted
    int i = 0; int j = 0; int k = 0;
    while (i < leftsize && j < rightsize)
    {
        if(arrayLeft[i] <= arrayRight[j]){
            array[k] = arrayLeft[i];
            i++;
        }
        else{
            array[k] = arrayRight[j];
            j++;
        }
        k++;
    }
    while (i < leftsize)
    {
        array[k] = arrayLeft[i];
        i++;
        k++;
    }
    while (j < rightsize)
    {
        array[k] = arrayRight[j];
        j++;
        k++;
    }
}

//quick sort
template<typename V>
void sorts::QuickSort(V* array, int start, int end){
    if(end <= start) return; //base case
    //pivot location
    int pivot = Partition(array, start, end);
    QuickSort(array, start, pivot - 1);
    QuickSort(array, pivot + 1, end);
}

template<typename V>
int sorts::Partition(V* array, int start, int end){
    V pivot = array[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j++){
        if(array[j] < pivot){
            i++;
            V temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    V temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    return i;
}