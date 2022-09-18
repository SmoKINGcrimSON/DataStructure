#include <iostream>
#include "../sorts/sort.h"

int main(){
    int nums[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(nums)/sizeof(nums[0]);
    sorts::InsertionSort(nums, size);
    for(int n : nums) std::cout<<n<<std::endl;
    return 0;
}