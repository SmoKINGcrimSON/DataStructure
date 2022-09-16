#include <iostream>

template<typename V>
class Node{
    public:
        V value;
        Node* next;
        Node* previous;
};

//Recorrer nodos dobles deade el head hasta el tail
template<typename V>
void PrintForward(Node<V>* head){
    Node<V>* traverser = head;
    while (traverser != NULL)
    {
        std::cout<<traverser->value<<std::endl;
        traverser = traverser->next;
    }
    
}

//Recorrer nodos dobles deade el tail hasta el head (reverso)
template<typename V>
void PrintBackward(Node<V>* tail){
    Node<V>* traverser = tail;
    while (traverser != NULL)
    {
        std::cout<<traverser->value<<std::endl;
        traverser = traverser->previous;
    }
    
}

int main(){
    //create head and tail for doublelinkedlist
    Node<int>* head;
    Node<int>* tail;
    //create first node
    Node<int>* node = new Node<int>();
    node->value = 4;
    node->next = NULL;
    node->previous = NULL;
    //equal
    head = node;
    tail = node;
    //second node
    node = new Node<int>();
    node->value = 5;
    node->next = NULL;
    node->previous = tail;
    tail->next = node;
    tail = node;
    //third node
    node = new Node<int>();
    node->value = 6;
    node->next = NULL;
    node->previous = tail;
    tail->next = node;
    tail = node;
    //fourth node
    node = new Node<int>();
    node->value = 7;
    node->next = NULL;
    node->previous = tail;
    tail->next = node;
    tail = node;
    //PrintForward
    std::cout<<"Print double linked list forward:"<<std::endl;
    PrintForward(head);
    //printbackward
    std::cout<<"Print double linked list backward:"<<std::endl;
    PrintBackward(tail);
    return 0;
}