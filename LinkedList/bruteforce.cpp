#include <iostream>

std::string BruteForce(std::string password){
    std::string breakpass;
    std::string library = "qwertyuiopñlkjhgfdsazxcvbnm1234567890QWERTYUIOPÑLKJHGFDSAZXCVBNM_-*{}/";
    int indexword = 0;
    while (breakpass != password)
    {
        for(int i = 0; i < library.size(); i++){
            if(library[i] == password[indexword]){
            breakpass += library.at(i);
            break;
            }
        }
        indexword++;
    }
    return breakpass;
}

int main(){
    std::string password;
    std::cout<<"Introduce your password: ";
    std::cin>>password;
    std::cout<<std::endl;
    //called bruteforce
    std::cout<<"your password is... this?\t"<<BruteForce(password);
    return 0;
}