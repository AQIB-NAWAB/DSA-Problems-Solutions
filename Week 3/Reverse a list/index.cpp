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

void reverseList(LinkedList* list){
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}
int main(){
    LinkedList* list = new LinkedList();
    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    reverseList(list);
    list->printList();
    list->append(5);
    list->append(6);
    list->append(7);
    list->append(8);
    list->printList();
    return 0;
}