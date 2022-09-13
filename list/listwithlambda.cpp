#include <iostream>
#include <algorithm>
#include <list>

int main(){
    int d = 2;
    std::list<int> nums = {1, 2, 3, 5, 7};
    std::for_each(nums.begin(), nums.end(), [=](int a){a % d == 0? std::cout<<a<<" not divisible by "<<d<<'\n' : std::cout<<a<<" divisible by "<<d<<'\n';});
    return 0;
}