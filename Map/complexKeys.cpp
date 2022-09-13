#include <iostream>
#include <map>
#include <string>
#include <list>

int main(){
    using std::string; using std::map; using std::list;
    map<string, list<string>> pokedex;
    list<string> pikachuAttacks{"thunder shock", "tail whip", "quick attack"};
    list<string> charmanderAttacks{"flame thrower", "scary face"};
    list<string> chikoritaAttacks{"razor leaf", "poison powder"};
    pokedex.insert(std::pair<string, list<string>>("pikachu", pikachuAttacks));
    pokedex.insert(std::pair<string, list<string>>("charmander", charmanderAttacks));
    pokedex.insert(std::pair<string, list<string>>("chikorita", chikoritaAttacks));
    for(auto pair: pokedex){
        std::cout<<"Pokemon name: "<<pair.first<<std::endl;
        int num = 0;
        for(auto attack : pair.second){
            num++;
            std::cout<<"Attack "<<num<<": "<<attack<<std::endl;
        }
        std::cout<<std::endl;
    }
    return 0;
}