#include <iostream>

template<typename E>
int linearsearch(const E*, const int, const E);

int main(){
    int nums[] = {1, 2, 3, 4 ,5 ,6 ,7};
    std::cout<<"199 at: "<<linearsearch(nums, 7, 199)<<" index."<<std::endl;
    std::cout<<"1 at: "<<linearsearch(nums, 7, 1)<<" index.";
}

template<typename E>
int linearsearch(const E* array, const int size, const E element){
    for(int i = 0; i < size; i++){
        if(array[i] == element){
            return i;
        }
    }
    return -1;
}