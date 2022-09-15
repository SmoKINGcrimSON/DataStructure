#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main(){
    std::list<std::string>* texts = new std::list<std::string>();
    while (true)
    {
        std::string text;
        std::cout<<"Fill list of strings (skip to end):\n";
        std::getline(std::cin, text);
        std::cout<<std::endl;
        if(text == "skip"){
            break;
        }
        texts->push_back(text);
    }
    std::cout<<std::endl;
    std::for_each(texts->begin(), texts->end(), [](std::string t){
        std::cout<<"Text: "<<t<<std::endl;
    });
    delete[] texts;
    return 0;
}