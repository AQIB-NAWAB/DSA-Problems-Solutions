#include <iostream>
#include <vector>
using namespace std;



class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }
    bool isEmpty() {
        return this->head == NULL;
    }
    void printList() {
        Node* current = this->head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    LinkedList* list = new LinkedList();
    
    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    if(list->isEmpty()){
        cout<<"List is empty"<<endl;
    }else{
        cout<<"List is not empty Here are the nodes"<<endl;
        list->printList();
    }
    

    return 0;
}

