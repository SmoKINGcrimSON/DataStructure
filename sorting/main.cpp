#include <iostream>
#include "sorts.h"
#include <ctime>

int main(){
    srand(time(0));
    //int array[] = {123, 34, 56, 34, 45, 56, 23, 12, 34};
    //int size = sizeof(array)/sizeof(array[0]);
    int size;
    std::cout<<"Size of the array: ";
    std::cin>>size;
    std::cout<<std::endl;
    int* array = new int[size];
    for(int i = 0; i < size; i++){
        *(array + i) = rand()%100000;
    }
    //merged sort
    sorts::QuickSort(array, 0, size - 1);
    //view elements
    for(int i = 0; i < size; i++) std::cout<<*(array + i)<<std::endl;
    delete[] array;
    array = nullptr;
    return 0;
}