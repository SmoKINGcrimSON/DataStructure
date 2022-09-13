#include <iostream>
#include <queue>
#include <string>

void Menu();
void OptionChoose(std::queue<std::string>&, const char);

int main(){
    Menu();
    return 0;
}

void Menu(){
    std::queue<std::string>* Tasks;
    Tasks = new std::queue<std::string>();
    bool run = true;
    while(run){
        char option;
        std::cout<<"w = Write new daily Task\ns = See all your tasks\nr = Remove top task\n";
        std::cout<<"c = Stop program\nyour choice: ";
        std::cin>>option;
        option = std::tolower(option);
        std::cout<<std::endl;
        OptionChoose(*Tasks, option);
        if(option == 'c'){
            run = false;
        }
    }
}

void OptionChoose(std::queue<std::string>& tasks, const char choice){
    switch (choice)
    {
        case 'w':{
            std::string newTask;
            std::cout<<"Write your new task: ";
            std::getline(std::cin>>std::ws, newTask);
            tasks.push(newTask);
            break;
        }
        case 's':{
            if(tasks.size() == 0){
                std::cout<<"Any task in your queue."<<std::endl;
                break;
            }
            std::queue temptasks = tasks;
            for(int i = 0; temptasks.empty() != true; i++){
                std::cout<<"Task number "<<i + 1<<": "<<temptasks.front()<<std::endl;
                temptasks.pop();
            }
            break;
        }
        case 'r':{
            std::cout<<"task: "<<tasks.front()<<" removed!"<<std::endl;
            tasks.pop();
            break;
        }
        case 'c':{
            std::cout<<"Thanks for using this program!!!"<<std::endl;
            break;
        }
        default:{
            std::cout<<"Not a valid operation!!!"<<std::endl;
            break;
        }
    }
    std::cout<<std::endl;
}