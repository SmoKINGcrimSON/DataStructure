#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

int main(){
    //doesnt order keys::
    std::unordered_map<std::string, std::string> myDictionarie;
    myDictionarie.insert(std::pair<std::string,std::string>("first", "Bryam"));
    myDictionarie.insert(std::pair<std::string,std::string>("second", "Alexander"));
    myDictionarie.insert(std::pair<std::string,std::string>("third", "Fernando"));
    myDictionarie.insert(std::pair<std::string,std::string>("fourth", "Nicolas"));
    for(auto pair : myDictionarie){
        std::cout<<pair.first<<" - "<<pair.second<<std::endl;
    }
    //order the kays::
    std::map<int, std::string> myDailyActivities;
    myDailyActivities.insert(std::pair<int, std::string>(1, "breakfast"));
    myDailyActivities.insert(std::pair<int, std::string>(2, "midmeat"));
    myDailyActivities.insert(std::pair<int, std::string>(3, "lunch"));
    myDailyActivities.insert(std::pair<int, std::string>(4, "dinner"));
    for(auto pair : myDailyActivities){
        std::cout<<pair.first<<" - "<<pair.second<<std::endl;
    }
    std::cout<<"myDailyActivities size: "<<myDailyActivities.size()<<std::endl;
    std::cout<<"myDictionarie size: "<<myDictionarie.size()<<std::endl;
    myDictionarie.clear();
    std::cout<<"myDictionarie size: "<<myDictionarie.size()<<std::endl;
    return 0;
}