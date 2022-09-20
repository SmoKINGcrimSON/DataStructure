#include <iostream>
#include "sorts.h"

int main(){
    int array[] = {3, 4, 1, 3, 2, 7, 4, 9, 2, 34};
    int size = sizeof(array)/sizeof(array[0]);
    sorts::MergedSort(array, size);
    for(int n : array) std::cout<<n<<std::endl;
    return 0;
}