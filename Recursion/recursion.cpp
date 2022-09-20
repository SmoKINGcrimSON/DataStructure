#include <iostream>

void walk(int);
int Factorial(int);
float power(float, int);

int main(){
    walk(10);
    std::cout<<Factorial(5)<<std::endl;
    std::cout<<power(2, 8)<<std::endl;
    return 0;
}

void walk(int steps){
    if(steps < 1) return; //base case
    std::cout<<"You take a step"<<std::endl;
    walk(steps - 1); //recursive
}

int Factorial(int num){
    if(num < 1) return 1;
    return num *= Factorial(num - 1);
}

float power(float base, int exponent){
    if(exponent < 1) return 1; //base case
    return base * power(base, exponent - 1);
}