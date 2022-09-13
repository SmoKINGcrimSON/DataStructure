#include <iostream>

template<typename V>
class Node{
    public:
        V value;
        Node* next;
        Node(V value){
            this->value = value;
        }
};

template<typename V>
void PrintList(Node<V>* n){
    while (n != NULL)
    {
        std::cout<<"Node value: "<<n->value<<std::endl;
        n = n->next;
    }
}

template<typename V>
void InsertAtFront(Node<V>** head, V newValue){
    //1.Prepare a NewNode
    Node<V>* newNode = new Node(newValue);
    //2.Put it in front of current head
    newNode->next = *head;
    //3.Move head of the list to point to new node
    *head = newNode;
}

template<typename V>
void InsertAtTheEnd(Node<V>** head, V newValue){
    //1. Prepare a Node
    Node<V>* newNode = new Node(newValue);
    newNode->next = NULL;
    //2. If linked list is empty, newNode will be a head Node
    if(*head == NULL){
        *head = newNode;
        return;
    }
    //3. Find the last Node
    Node<V>* last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    //4. Insert newNode after last node
    last->next = newNode;
}

template<typename V>
void InsertAfter(Node<V>* previous, V newValue){
    //1. check if previous node is NULL
    if(previous == NULL){
        std::cout<<"Previous can not be null!"<<std::endl;
        return;
    }
    //2. Prepare a newNode
    Node<V>* newNode = new Node(newValue);
    //3. Insert newNode afterPrevious
    newNode->next = previous->next;
    previous->next = newNode;
}

int main(){
    Node<int>* head = new Node<int>(13);
    Node<int>* second = new Node<int>(19);
    Node<int>* third = new Node<int>(16);
    //
    head->next = second;
    second->next = third;
    third->next = NULL;
    //
    InsertAfter(second, 21);
    PrintList(head);
    return 0;
}