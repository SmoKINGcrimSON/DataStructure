#include <iostream>
#include <ctime>
#include "quicksort.h"

int main(){
    srand(time(0));
    int size;
    std::cout<<"Introduce the number of the index: ";
    std::cin>>size;
    std::cout<<std::endl;
    int* array = new int[size];
    for(int i = 0; i < size; i++){
        *(array + i) = rand()%100;
    }
    QuickSort(array, 0, size - 1);
    for(int i = 0; i < size; i++){
        std::cout<<*(array + i)<<std::endl;
    }
    delete[] array;
    array = nullptr;
    if(array == nullptr) std::cout<<"array eliminated.";
    return 0;
}