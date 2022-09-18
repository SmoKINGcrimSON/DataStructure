#include <iostream>

long Factorial(long);

int main(){
    std::cout<<Factorial(20);
    return 0;
}

long Factorial(long num){
    if(num < 1) return 1;
    return num *= Factorial(num - 1);
}