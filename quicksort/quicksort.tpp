#include "quicksort.h"

template<typename V>
void QuickSort(V* array, int lowindex, int highindex){
    //1. recursive condition
    if(lowindex >= highindex) return;
    //2. Stablish the pivot
    int pivotindex = lowindex + rand()%(highindex - lowindex);
    V pivot = array[pivotindex];
    Swap(array, pivotindex, highindex);
    //3. Partition
    int leftpointer = lowindex;
    int rightpointer = highindex;
    while (leftpointer < rightpointer)
    {
        while (array[leftpointer] <= pivot && leftpointer < rightpointer)
        {
            leftpointer++;
        }
        while(array[rightpointer] >= pivot && leftpointer < rightpointer){
            rightpointer--;
        }
        Swap(array, leftpointer, rightpointer);
    }
    Swap(array, leftpointer, highindex);
    //4. Recursive smaller arrays for left and right
    QuickSort(array, lowindex, leftpointer - 1);
    QuickSort(array, leftpointer + 1, highindex);
}

template<typename V>
void Swap(V* array, int index1, int index2){
    V temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}