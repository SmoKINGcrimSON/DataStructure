#include "sorts.h"

template<typename V>
int sorts::BynarySearch(const V* array, V value, const int size){
int low = 0;
int high = size - 1;
int middle;

while (low <= high)
{
    middle = (low + high) / 2;
    if(array[middle] > value){
        high = middle - 1;
    }
    else if(array[middle] < value){
        low = middle + 1;
    }
    else return middle;
}
return -1;
}

//merged sort

template<typename V>
void sorts::MergedSort(V* array, const int size){
    //if sort is below or equal one, stop recursivity
    if(size <= 1) return;
    //arrays size
    int lenght = size;
    int lenghtleft = size / 2;
    int lenghtright = lenght - lenghtleft;
    //create arrays to merged
    V leftarray[lenghtleft];
    V rightarray[lenghtright];
    //pass values to new arrays
    int j = 0;
    for(int i = 0; i < lenght; i++){
        if(i < lenghtleft){
            leftarray[i] = array[i];
        }
        else{
            rightarray[j] = array[i];
            j++;
        }
    }
    //recursivity
    MergedSort(leftarray, lenghtleft);
    MergedSort(rightarray, lenghtright);
    //merge
    Merge(array, lenght, leftarray, lenghtleft, rightarray, lenghtright);
}

template<typename V>
void sorts::Merge(V* array, const int size, V* leftarray, const int sizeL, V* rightarray, const int sizeR){
    int lenghtleft = sizeL;
    int lenghtright = sizeR;
    int i = 0; int j = 0; int k = 0;
    while (i < lenghtleft && j < lenghtright)
    {
        if(leftarray[i] <= rightarray[j]){
            array[k] = leftarray[i];
            i++;
        }
        else{
            array[k] = rightarray[j];
            j++;
        }
        k++;
    }
    while (i < lenghtleft)
    {
        array[k] = leftarray[i];
        i++;
        k++;
    }
    while (j < lenghtright)
    {
        array[k] = rightarray[j];
        j++;
        k++;
    }
}