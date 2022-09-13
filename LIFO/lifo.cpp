#include <iostream>
#include <stack>

template<typename T>
void PrintStackElements(std::stack<T> stck){
    while (stck.empty() != true)
    {
        std::cout<<stck.top()<<std::endl;
        stck.pop();
    }
    
}

int main(){
    //Important Methods: empty, size, push, pop, top
    std::stack<double> numberStack;
    numberStack.push(123.4);
    numberStack.push(23.4);
    numberStack.push(112321.4);
    if(numberStack.empty()) std::cout<<"stack is empty";
    else std::cout<<"Stack is not empty";
    std::cout<<std::endl;
    std::cout<<"Stack size is: "<<numberStack.size()<<std::endl;
    PrintStackElements(numberStack);
    return 0;
}