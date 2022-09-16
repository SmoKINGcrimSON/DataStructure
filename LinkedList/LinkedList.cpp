#include <iostream>
#include <regex>

class Enemy{
    private:
        std::string name = "NaN";
        float hp = 0;
    public:
        //constructors
        Enemy(std::string name, float hp){
            setNAME(name);
            setHP(hp);
        }
        Enemy(){

        }
        //getters
        std::string getNAME(){
            return this->name;
        }
        float getHP(){
            return this->hp;
        }
        //setters
        void setNAME(std::string name){
            std::string pattern = "^[a-zA-Z]+$";
            std::regex regexName(pattern);
            std::regex_match(name, regexName)? this->name = name : this->name = "NaN"; 
        }
        void setHP(float hp){
            hp > 0 && hp < 100? this->hp = hp : this->hp = 0;
        }
        //setters
        void addHP(float hp){
            if(hp > 0 && hp + this->hp <= 100) this->hp += hp;
        }
        void substractHP(float hp){
            if(hp > 0 && this->hp - hp > 0) this->hp -= hp;
        }
};

std::ostream& operator<<(std::ostream& cout, Enemy& enemy){
    cout<<"Enemy name: "<<enemy.getNAME()<<"\nEnemy hp: "<<enemy.getHP()<<std::endl;
    return cout;
}

template<typename V>
class Node{
    public:
        V value;
        Node* next;
        Node(V value){
            this->value = value;
        }
        ~Node(){

        }
};

template<typename V>
//Recorrer un linkedlist
void PrintList(Node<V>* head){
    for(Node<V>* index = head; index != NULL; index = index->next){
        std::cout<<index->value<<std::endl;
    }    
}

//Insertar en el head un nuevo node
template<typename V>
void InsertAtTheFront(Node<V>** head, V value){
    //1. Prepare a new node
    Node<V>* newValue = new Node<V>(value);
    //2. Put it in front of the current head
    newValue->next = *head;
    //3. Move head of the list to point to the new node
    *head = newValue;
}

//Insertar en el tail un nuevo node
template<typename V>
void InsertAtTheEnd(Node<V>** head, V value){
    //1. Prepare a new node
    Node<V>* newValue = new Node<V>(value);
    newValue->next = NULL;
    //2.If linked list is empty, newnode will be a head node
    if(head == NULL){
        *head = newValue;
        return;
    }
    //3. Find the last Node
    Node<V>* tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    //4. Insert newNode after last node (at the end)
    tail->next = newValue;
}

//Insertar node después de otro nodo
template<typename V>
void InsertAfter(Node<V>* previous, V value){
    //1.- Check if previous node is NULL
    if(previous == NULL){
        std::cout<<"Previous can not be NULL";
        return;
    }
    //2.- Prepare a newNode
    Node<V>* newNode = new Node<V>(value);
    //3.- Insert newNode after previous
    newNode->next = previous->next;
    previous->next = newNode;
}

int main(){
    Node<Enemy>* head = new Node<Enemy>(Enemy("kalak", 14.5f));
    Node<Enemy>* second = new Node<Enemy>(Enemy("Eledin", 15.6f));
    Node<Enemy>* third = new Node<Enemy>(Enemy("Fion", 13.6f));
    head->next = second;
    second->next = third;
    third->next = NULL;
    //InsertAtTheFront(&head, Enemy("ilag", 14.6f));
    //InsertAtTheEnd(&head, Enemy("Alfeim", 5.6f));
    InsertAfter(head, Enemy("generic", 20.5f));
    PrintList(head);
    delete head;
    head = NULL;
    delete second;
    second = NULL;
    delete third;
    third = NULL;
    
    return 0;
}