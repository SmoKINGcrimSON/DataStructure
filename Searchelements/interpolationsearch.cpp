#include <iostream>

int InterpolationSearch(const int*, const int, const int);
int main(){
    int array[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int size = sizeof(array)/sizeof(array[0]);
    int index = InterpolationSearch(array, size, 256);
    if(index != -1){
        std::cout<<"Element found at index: "<<index;
    }
    else std::cout<<"Element not found";
    return 0;
}

int InterpolationSearch(const int* pArray, const int size, const int value){
    int high = size - 1;
    int low = 0;
    while (value >= pArray[low] && value <= pArray[high] && low <= high)
    {
        int guess = low + (high - low) * (value - pArray[low]) / (pArray[high] - pArray[low]);
        std::cout<<"guess: "<<guess<<std::endl;
        if(pArray[guess] == value){
            return guess;
        }
        else if(pArray[guess] < value){
            low = guess + 1;
        }
        else{
            high = guess - 1;
        }
    }
    return -1;
}