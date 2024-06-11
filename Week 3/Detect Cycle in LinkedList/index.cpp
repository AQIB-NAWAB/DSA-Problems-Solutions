#include<iostream>
#include<vector>
#include<unordered_set>
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




bool detectCycle(LinkedList* list){
    unordered_set<Node*> set;
    Node* current = list->head;
    while(current != NULL){
        if(set.find(current) != set.end()){
            return true;
        }
        set.insert(current);
        current = current->next;
    }
    return false;
}

int main(){

    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    list.tail->next = list.head->next->next;


    if(detectCycle(&list)){
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return  0;
}