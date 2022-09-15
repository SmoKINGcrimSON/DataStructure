#include <iostream>

template<typename V>
class Node{
    public:
        V value;
        Node* next;
        Node* previous;
};

template<typename T>
void PrintForward(Node<T>* head){
    Node<T>* traverser = head;
    while (traverser != nullptr)
    {
        std::cout<<traverser->value<<std::endl;
        traverser = traverser->next;
    }
    
}

template<typename T>
void PrintBackward(Node<T>* tail){
    Node<T>* traverser = tail;
    while (traverser != nullptr)
    {
        std::cout<<traverser->value<<std::endl;
        traverser = traverser->previous;
    }
    
}

int main(){
    //head and tail
    Node<int>* head;
    Node<int>* tail;
    //1st node
    Node<int>* node = new Node<int>();
    node->value = 4;
    node->next = nullptr;
    node->previous = nullptr;
    //assignment
    head = node;
    tail = node;
    //2d node
    node = new Node<int>();
    node->value = 5;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    //3d node
    node = new Node<int>();
    node->value = 6;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    //4d node
    node = new Node<int>();
    node->value = 7;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    std::cout<<"Print backward: "<<std::endl;
    PrintBackward(tail);
    std::cout<<"Print Forward: "<<std::endl;
    PrintForward(head);
    return 0;
}